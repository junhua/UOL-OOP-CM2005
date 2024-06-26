#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include <numeric>
#include <string>
#include "Candlestick.h"
#include "WeatherData.h"
#include "WeatherAnalyzer.h"

WeatherAnalyzer::WeatherAnalyzer(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string dateString;
        std::getline(ss, dateString, ',');
        Date date(dateString.substr(0, 10));

        std::vector<double> temps;
        std::string temp;
        while (std::getline(ss, temp, ','))
        {
            temps.push_back(std::stod(temp));
        }

        data.emplace_back(date, temps);
    }
}

std::vector<Candlestick> WeatherAnalyzer::computeCandlesticks(const std::string &country, const std::string &timeframe)
{
    std::vector<Candlestick> result;
    std::vector<double> yearlyTemps;
    int currentYear = data[0].getDate().getYear();

    for (const auto &weatherData : data)
    {
        double temp = weatherData.getTemperature(country);
        if (weatherData.getDate().getYear() == currentYear)
        {
            yearlyTemps.push_back(temp);
        }
        else
        {
            double open = result.empty() ? yearlyTemps[0] : result.back().getClose();
            double close = std::accumulate(yearlyTemps.begin(), yearlyTemps.end(), 0.0) / yearlyTemps.size();
            double high = *std::max_element(yearlyTemps.begin(), yearlyTemps.end());
            double low = *std::min_element(yearlyTemps.begin(), yearlyTemps.end());

            result.emplace_back(Date(currentYear, 1, 1), open, high, low, close);

            currentYear = weatherData.getDate().getYear();
            yearlyTemps.clear();
            yearlyTemps.push_back(temp);
        }
    }

    // Process the last year
    if (!yearlyTemps.empty())
    {
        double open = result.empty() ? yearlyTemps[0] : result.back().getClose();
        double close = std::accumulate(yearlyTemps.begin(), yearlyTemps.end(), 0.0) / yearlyTemps.size();
        double high = *std::max_element(yearlyTemps.begin(), yearlyTemps.end());
        double low = *std::min_element(yearlyTemps.begin(), yearlyTemps.end());

        result.emplace_back(Date(currentYear, 1, 1), open, high, low, close);
    }

    return result;
}

void WeatherAnalyzer::plotCandlesticks(const std::vector<Candlestick> &candlesticks)
{
    const int plotHeight = 20;
    const int plotWidth = candlesticks.size() * 4; // Increased to add space between plots

    double minTemp = candlesticks[0].getLow();
    double maxTemp = candlesticks[0].getHigh();
    for (const auto &c : candlesticks)
    {
        minTemp = std::min(minTemp, c.getLow());
        maxTemp = std::max(maxTemp, c.getHigh());
    }

    std::vector<std::string> plot(plotHeight + 1, std::string(plotWidth + 6, ' '));

    for (int i = 0; i < candlesticks.size(); ++i)
    {
        const auto &c = candlesticks[i];
        int x = i * 4 + 6; // Changed to 4 to add space
        int openY = plotHeight - 1 - (c.getOpen() - minTemp) / (maxTemp - minTemp) * (plotHeight - 1);
        int closeY = plotHeight - 1 - (c.getClose() - minTemp) / (maxTemp - minTemp) * (plotHeight - 1);
        int highY = plotHeight - 1 - (c.getHigh() - minTemp) / (maxTemp - minTemp) * (plotHeight - 1);
        int lowY = plotHeight - 1 - (c.getLow() - minTemp) / (maxTemp - minTemp) * (plotHeight - 1);

        for (int y = highY; y <= lowY; ++y)
        {
            plot[y][x + 1] = '|';
        }

        char bodyChar = (c.getOpen() > c.getClose()) ? '-' : '+';
        int startY = std::min(openY, closeY);
        int endY = std::max(openY, closeY);
        for (int y = startY; y <= endY; ++y)
        {
            plot[y][x] = bodyChar;
            plot[y][x + 1] = bodyChar;
            plot[y][x + 2] = bodyChar;
        }
    }

    // Add Y-axis
    for (int y = 0; y < plotHeight; ++y)
    {
        plot[y][5] = '|';
        if (y % 5 == 0)
        {
            double temp = maxTemp - (y * (maxTemp - minTemp) / (plotHeight - 1));
            std::string tempStr = std::to_string(static_cast<int>(temp));
            for (size_t i = 0; i < tempStr.length(); ++i)
            {
                plot[y][4 - i] = tempStr[tempStr.length() - 1 - i];
            }
        }
    }

    // Add X-axis
    for (int x = 6; x < plotWidth + 6; ++x)
    {
        plot[plotHeight][x] = '-';
    }
    for (int i = 0; i < candlesticks.size(); i += 5)
    {
        int x = i * 4 + 6; // Changed to 4 to match the new spacing
        std::string yearStr = std::to_string(candlesticks[i].getDate().getYear());
        for (size_t j = 0; j < yearStr.length(); ++j)
        {
            plot[plotHeight][x + j] = yearStr[j];
        }
    }

    for (const auto &row : plot)
    {
        std::cout << row << std::endl;
    }
}

std::vector<WeatherData> WeatherAnalyzer::filterData(const Date &startDate, const Date &endDate, const std::string &country, double minTemp, double maxTemp)
{
    std::vector<WeatherData> filteredData;
    for (const auto &wd : data)
    {
        if (wd.getDate() < startDate || endDate < wd.getDate())
            continue;
        double temp = wd.getTemperature(country);
        if (temp < minTemp || temp > maxTemp)
            continue;
        filteredData.push_back(wd);
    }
    return filteredData;
}

std::vector<std::pair<int, double>> WeatherAnalyzer::predictTemperature(const std::string& country, const Date& startDate, int yearsAhead) {
    // Simple linear regression
    std::vector<double> x, y;
    for (const auto& wd : data) {
        x.push_back(wd.getDate().getYear());
        y.push_back(wd.getTemperature(country));
    }

    double sumX = std::accumulate(x.begin(), x.end(), 0.0);
    double sumY = std::accumulate(y.begin(), y.end(), 0.0);
    double sumXY = std::inner_product(x.begin(), x.end(), y.begin(), 0.0);
    double sumX2 = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);

    double n = x.size();
    double slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double intercept = (sumY - slope * sumX) / n;

    std::vector<std::pair<int, double>> predictions;
    for (int i = 0; i <= yearsAhead; ++i) {
        int year = startDate.getYear() + i;
        double predictedTemp = slope * year + intercept;
        predictions.emplace_back(year, predictedTemp);
    }

    return predictions;
}


void WeatherAnalyzer::plotTemperatureLineChart(const std::string& country, int forecastYears) {
    const int plotHeight = 20;
    const int plotWidth = 80;

    // Gather historical data
    std::vector<std::pair<int, double>> historicalData;
    for (const auto& wd : data) {
        int year = wd.getDate().getYear();
        double temp = wd.getTemperature(country);
        if (historicalData.empty() || historicalData.back().first != year) {
            historicalData.emplace_back(year, temp);
        } else {
            historicalData.back().second = (historicalData.back().second + temp) / 2.0;
        }
    }

    // Get forecast data
    Date lastDate(historicalData.back().first, 12, 31);
    auto forecastData = predictTemperature(country, lastDate, forecastYears);

    // Combine historical and forecast data
    std::vector<std::pair<int, double>> allData = historicalData;
    allData.insert(allData.end(), forecastData.begin() + 1, forecastData.end());

    // Find min and max temperatures
    auto [minIt, maxIt] = std::minmax_element(allData.begin(), allData.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; });
    double minTemp = minIt->second;
    double maxTemp = maxIt->second;

    // Create plot
    std::vector<std::string> plot(plotHeight + 1, std::string(plotWidth, ' '));

    // Plot data points
    for (size_t i = 0; i < allData.size(); ++i) {
        int x = static_cast<int>(i * (plotWidth - 1) / (allData.size() - 1));
        int y = plotHeight - 1 - static_cast<int>((allData[i].second - minTemp) / (maxTemp - minTemp) * (plotHeight - 1));
        plot[y][x] = (i < historicalData.size()) ? '*' : 'o';
    }

    // Add Y-axis
    for (int y = 0; y < plotHeight; ++y) {
        plot[y][0] = '|';
        if (y % 5 == 0) {
            double temp = maxTemp - (y * (maxTemp - minTemp) / (plotHeight - 1));
            std::string tempStr = std::to_string(static_cast<int>(temp));
            for (size_t i = 0; i < tempStr.length() && i < 5; ++i) {
                plot[y][i + 1] = tempStr[i];
            }
        }
    }

    // Add X-axis
    for (int x = 0; x < plotWidth; ++x) {
        plot[plotHeight][x] = '-';
    }

    // Add year labels
    for (size_t i = 0; i < allData.size(); i += allData.size() / 5) {
        int x = static_cast<int>(i * (plotWidth - 1) / (allData.size() - 1));
        std::string yearStr = std::to_string(allData[i].first);
        for (size_t j = 0; j < yearStr.length() && x + j < plotWidth; ++j) {
            plot[plotHeight][x + j] = yearStr[j];
        }
    }

    // Print the plot
    std::cout << "Temperature Line Chart for " << country << " (historical * and forecast o)" << std::endl;
    for (const auto& row : plot) {
        std::cout << row << std::endl;
    }
}

