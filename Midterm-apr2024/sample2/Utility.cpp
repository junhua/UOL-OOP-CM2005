
#include "Utility.h"
#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <fstream>
#include "WeatherEntry.h"
#include "Candlestick.h"
#include "WeatherEntries.h"

std::string Utility::ccToString(CountryCode cc)
{
    static const std::map<CountryCode, std::string> ccMap = {
        {CountryCode::AT, "AT"}, {CountryCode::BE, "BE"}, {CountryCode::BG, "BG"}, {CountryCode::CH, "CH"}, {CountryCode::CZ, "CZ"}, {CountryCode::DE, "DE"}, {CountryCode::DK, "DK"}, {CountryCode::EE, "EE"}, {CountryCode::ES, "ES"}, {CountryCode::FI, "FI"}, {CountryCode::FR, "FR"}, {CountryCode::GB, "GB"}, {CountryCode::GR, "GR"}, {CountryCode::HR, "HR"}, {CountryCode::HU, "HU"}, {CountryCode::IE, "IE"}, {CountryCode::IT, "IT"}, {CountryCode::LT, "LT"}, {CountryCode::LU, "LU"}, {CountryCode::LV, "LV"}, {CountryCode::NL, "NL"}, {CountryCode::NO, "NO"}, {CountryCode::PL, "PL"}, {CountryCode::PT, "PT"}, {CountryCode::RO, "RO"}, {CountryCode::SE, "SE"}, {CountryCode::SI, "SI"}, {CountryCode::SK, "SK"}, {CountryCode::UNKNOWN, "UNKNOWN"}};
    auto it = ccMap.find(cc);
    return (it != ccMap.end()) ? it->second : "UNKNOWN";
}

CountryCode Utility::stringToCC(std::string cc)
{
    static const std::map<std::string, CountryCode> ccMap = {
        {"AT", CountryCode::AT}, {"BE", CountryCode::BE}, {"BG", CountryCode::BG}, {"CH", CountryCode::CH}, {"CZ", CountryCode::CZ}, {"DE", CountryCode::DE}, {"DK", CountryCode::DK}, {"EE", CountryCode::EE}, {"ES", CountryCode::ES}, {"FI", CountryCode::FI}, {"FR", CountryCode::FR}, {"GB", CountryCode::GB}, {"GR", CountryCode::GR}, {"HR", CountryCode::HR}, {"HU", CountryCode::HU}, {"IE", CountryCode::IE}, {"IT", CountryCode::IT}, {"LT", CountryCode::LT}, {"LU", CountryCode::LU}, {"LV", CountryCode::LV}, {"NL", CountryCode::NL}, {"NO", CountryCode::NO}, {"PL", CountryCode::PL}, {"PT", CountryCode::PT}, {"RO", CountryCode::RO}, {"SE", CountryCode::SE}, {"SI", CountryCode::SI}, {"SK", CountryCode::SK}};
    auto it = ccMap.find(cc);
    return (it != ccMap.end()) ? it->second : CountryCode::UNKNOWN;
}

std::vector<Candlestick> Utility::computeCandlestick(WeatherEntries entries)
{
    std::vector<Candlestick> candles;
    std::map<std::string, std::vector<double>> yearlyData;

    for (const WeatherEntry &entry : entries.entries)
    {
        std::string year = entry.utc_timestamp.substr(0, 4);
        for (const auto &[cc, temp] : entry.tempMap)
        {
            yearlyData[year + "_" + ccToString(cc)].push_back(temp);
        }
    }

    for (const auto &[key, temps] : yearlyData)
    {
        size_t underscorePos = key.find('_');
        std::string year = key.substr(0, underscorePos);
        std::string country = key.substr(underscorePos + 1);

        double open = candles.empty() ? temps[0] : candles.back().close;
        Candlestick candle({year, temps}, open);
        candle.cc = stringToCC(country);
        candles.push_back(candle);
    }

    return candles;
}

std::vector<std::string> Utility::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    std::istringstream iss(csvLine);
    std::string token;
    while (std::getline(iss, token, separator))
    {
        tokens.push_back(token);
    }
    return tokens;
}

WeatherEntry Utility::stringsToWeatherEntry(std::vector<std::string> tokens)
{
    WeatherEntry entry;
    entry.utc_timestamp = tokens[0];

    for (size_t i = 1; i < tokens.size(); ++i)
    {
        CountryCode cc = static_cast<CountryCode>(i - 1);
        entry.tempMap[cc] = std::stod(tokens[i]);
    }

    return entry;
}

WeatherEntries Utility::readCSV(std::string filename)
{
    std::vector<WeatherEntry> entries;
    std::ifstream csvFile(filename);

    if (!csvFile.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return WeatherEntries();
    }

    std::string line;

    // Skip header
    std::getline(csvFile, line);

    while (std::getline(csvFile, line))
    {
        try
        {
            WeatherEntry entry = stringsToWeatherEntry(tokenise(line, ','));
            entries.push_back(entry);
        }
        catch (const std::exception &e)
        {
            std::cerr << "CSVReader::readCSV bad data: " << e.what() << std::endl;
        }
    }

    std::cout << "Read " << entries.size() << " entries from CSV file." << std::endl;
    return WeatherEntries(entries);
}

std::vector<std::pair<int, double>> Utility::predictTemperature(const WeatherEntries &entries, const std::string &country, int yearsAhead)
{
    std::map<int, std::vector<double>> yearlyTemps;

    // Collect all temperatures for each year
    for (const auto &entry : entries.entries)
    {
        int year = std::stoi(entry.utc_timestamp.substr(0, 4));
        double temp = entry.tempMap.at(stringToCC(country));
        yearlyTemps[year].push_back(temp);
    }

    std::vector<std::pair<int, double>> historicalData;

    // Calculate accurate yearly averages
    for (const auto &[year, temps] : yearlyTemps)
    {
        double avg = std::accumulate(temps.begin(), temps.end(), 0.0) / temps.size();
        historicalData.emplace_back(year, avg);
    }

    // Sort historical data by year
    std::sort(historicalData.begin(), historicalData.end());

    // Simple Exponential Smoothing
    double alpha = 0.3; // Smoothing factor
    std::vector<double> smoothed = {historicalData[0].second};

    for (size_t i = 1; i < historicalData.size(); ++i)
    {
        double value = alpha * historicalData[i].second + (1 - alpha) * smoothed.back();
        smoothed.push_back(value);
    }

    // Calculate the average change in the last few years
    int numYearsForTrend = std::min(10, static_cast<int>(smoothed.size()));
    double avgChange = 0;
    for (int i = smoothed.size() - numYearsForTrend; i < smoothed.size() - 1; ++i)
    {
        avgChange += smoothed[i + 1] - smoothed[i];
    }
    avgChange /= (numYearsForTrend - 1);

    std::vector<std::pair<int, double>> predictions;
    int lastYear = historicalData.back().first;
    double lastValue = smoothed.back();

    for (int i = 0; i <= yearsAhead; ++i)
    {
        int year = lastYear + i;
        double predictedTemp = lastValue + avgChange * i;
        predictions.emplace_back(year, predictedTemp);
    }

    return predictions;
}

void Utility::plotTemperatureLineChart(const std::vector<std::pair<int, double>> &historicalData, const std::vector<std::pair<int, double>> &predictedData)
{
    const int plotHeight = 20;
    const int plotWidth = 80;

    auto allData = historicalData;
    allData.insert(allData.end(), predictedData.begin(), predictedData.end());

    auto [minIt, maxIt] = std::minmax_element(allData.begin(), allData.end(),
                                              [](const auto &a, const auto &b)
                                              { return a.second < b.second; });
    double minTemp = minIt->second;
    double maxTemp = maxIt->second;

    std::vector<std::string> plot(plotHeight + 1, std::string(plotWidth, ' '));

    // Plot historical data
    for (size_t i = 1; i < historicalData.size(); ++i)
    {
        int x1 = static_cast<int>((i - 1) * (plotWidth - 1) / (allData.size() - 1));
        int x2 = static_cast<int>(i * (plotWidth - 1) / (allData.size() - 1));
        int y1 = plotHeight - 1 - static_cast<int>((historicalData[i - 1].second - minTemp) / (maxTemp - minTemp) * (plotHeight - 1));
        int y2 = plotHeight - 1 - static_cast<int>((historicalData[i].second - minTemp) / (maxTemp - minTemp) * (plotHeight - 1));

        // Draw line between points
        int dx = std::abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
        int dy = -std::abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
        int err = dx + dy, e2;

        while (true)
        {
            plot[y1][x1] = '*';
            if (x1 == x2 && y1 == y2)
                break;
            e2 = 2 * err;
            if (e2 >= dy)
            {
                err += dy;
                x1 += sx;
            }
            if (e2 <= dx)
            {
                err += dx;
                y1 += sy;
            }
        }
    }

    // Plot predicted data
    for (size_t i = 1; i < predictedData.size(); ++i)
    {
        int x1 = static_cast<int>((historicalData.size() + i - 1) * (plotWidth - 1) / (allData.size() - 1));
        int x2 = static_cast<int>((historicalData.size() + i) * (plotWidth - 1) / (allData.size() - 1));
        int y1 = plotHeight - 1 - static_cast<int>((predictedData[i - 1].second - minTemp) / (maxTemp - minTemp) * (plotHeight - 1));
        int y2 = plotHeight - 1 - static_cast<int>((predictedData[i].second - minTemp) / (maxTemp - minTemp) * (plotHeight - 1));

        // Draw line between points
        int dx = std::abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
        int dy = -std::abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
        int err = dx + dy, e2;

        while (true)
        {
            plot[y1][x1] = 'o';
            if (x1 == x2 && y1 == y2)
                break;
            e2 = 2 * err;
            if (e2 >= dy)
            {
                err += dy;
                x1 += sx;
            }
            if (e2 <= dx)
            {
                err += dx;
                y1 += sy;
            }
        }
    }

    // Add axes and labels
    for (int y = 0; y < plotHeight; ++y)
    {
        plot[y][0] = '|';
        if (y % 5 == 0)
        {
            double temp = maxTemp - (y * (maxTemp - minTemp) / (plotHeight - 1));
            std::string tempStr = std::to_string(static_cast<int>(temp));
            for (size_t i = 0; i < tempStr.length() && i < 5; ++i)
            {
                plot[y][i + 1] = tempStr[i];
            }
        }
    }

    for (int x = 0; x < plotWidth; ++x)
    {
        plot[plotHeight][x] = '-';
    }

    for (size_t i = 0; i < allData.size(); i += allData.size() / 5)
    {
        int x = static_cast<int>(i * (plotWidth - 1) / (allData.size() - 1));
        std::string yearStr = std::to_string(allData[i].first);
        for (size_t j = 0; j < yearStr.length() && x + j < plotWidth; ++j)
        {
            plot[plotHeight][x + j] = yearStr[j];
        }
    }

    // Print the plot
    std::cout << "Temperature Line Chart (historical * and forecast o)" << std::endl;
    for (const auto &row : plot)
    {
        std::cout << row << std::endl;
    }
}
