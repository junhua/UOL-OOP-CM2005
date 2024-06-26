#include "WeatherMain.h"
#include "Utility.h"
#include <iostream>
#include <vector>
#include <map>

WeatherMain::WeatherMain() {}

void WeatherMain::init()
{
    weatherEntries = Utility::readCSV("data.csv");
    if (weatherEntries.entries.empty())
    {
        std::cerr << "Error: No data read from CSV file." << std::endl;
        return;
    }

    std::cout << "Successfully read " << weatherEntries.entries.size() << " entries from CSV file." << std::endl;

    while (true)
    {
        printMenu();

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            handleCandlestick();
            break;
        }
        case 2:
        {
            handlePrediction();
            break;
        }
        case 3:
        {
            std::cout << "Exiting program." << std::endl;
            return;
        }
        default:
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }
    }
}

void WeatherMain::handleCandlestick()
{
    std::string countryCode;
    std::cout << "Enter country code for candlestick plot: ";
    std::cin >> countryCode;

    auto candlesticks = Utility::computeCandlestick(weatherEntries);
    std::cout << "Computed " << candlesticks.size() << " total candlesticks." << std::endl;

    auto countryCandlesticks = std::vector<Candlestick>();

    for (const auto &c : candlesticks)
    {
        if (Utility::ccToString(c.cc) == countryCode)
        {
            countryCandlesticks.push_back(c);
        }
    }

    std::cout << "Found " << countryCandlesticks.size() << " candlesticks for " << countryCode << std::endl;

    if (countryCandlesticks.empty())
    {
        std::cout << "No data available for the specified country code." << std::endl;
    }
    else
    {
        plotCandlesticks(countryCandlesticks);
    }
}

void WeatherMain::handlePrediction()
{
    std::string countryCode;
    std::cout << "Enter country code for temperature prediction: ";
    std::cin >> countryCode;

    int yearsAhead;
    std::cout << "Enter number of years to predict: ";
    std::cin >> yearsAhead;

    // Compute historical average temperatures
    std::map<int, double> yearlyAvg;
    std::map<int, int> yearlyCount;
    for (const auto &entry : weatherEntries.entries)
    {
        int year = std::stoi(entry.utc_timestamp.substr(0, 4));
        double temp = entry.tempMap.at(Utility::stringToCC(countryCode));
        yearlyAvg[year] += temp;
        yearlyCount[year]++;
    }

    std::vector<std::pair<int, double>> historicalData;
    for (const auto &[year, sum] : yearlyAvg)
    {
        historicalData.emplace_back(year, sum / yearlyCount[year]);
    }
    std::sort(historicalData.begin(), historicalData.end());

    // Predict future temperatures
    auto predictedData = Utility::predictTemperature(weatherEntries, countryCode, yearsAhead);

    // Plot the data
    Utility::plotTemperatureLineChart(historicalData, predictedData);
}

void WeatherMain::printMenu()
{
    std::cout << "\nWeather App v1.0" << std::endl;
    std::cout << "1: Print candlestick plot" << std::endl;
    std::cout << "2: Predict and plot temperature" << std::endl;
    std::cout << "3: Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void WeatherMain::plotCandlesticks(const std::vector<Candlestick> &candlesticks)
{
    const int plotHeight = 20;
    const int plotWidth = candlesticks.size() * 4;

    double minTemp = candlesticks[0].low;
    double maxTemp = candlesticks[0].high;
    for (const auto &c : candlesticks)
    {
        minTemp = std::min(minTemp, c.low);
        maxTemp = std::max(maxTemp, c.high);
    }

    std::vector<std::string> plot(plotHeight + 1, std::string(plotWidth + 6, ' '));

    for (int i = 0; i < candlesticks.size(); ++i)
    {
        const auto &c = candlesticks[i];
        int x = i * 4 + 6;
        int openY = plotHeight - 1 - (c.open - minTemp) / (maxTemp - minTemp) * (plotHeight - 1);
        int closeY = plotHeight - 1 - (c.close - minTemp) / (maxTemp - minTemp) * (plotHeight - 1);
        int highY = plotHeight - 1 - (c.high - minTemp) / (maxTemp - minTemp) * (plotHeight - 1);
        int lowY = plotHeight - 1 - (c.low - minTemp) / (maxTemp - minTemp) * (plotHeight - 1);

        for (int y = highY; y <= lowY; ++y)
        {
            plot[y][x + 1] = '|';
        }

        char bodyChar = (c.open > c.close) ? '-' : '+';
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
        int x = i * 4 + 6;
        std::string yearStr = candlesticks[i].date;
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

void WeatherMain::predictAndPlotTemperature()
{
    std::string countryCode;
    std::cout << "Enter country code: ";
    std::cin >> countryCode;

    int yearsAhead;
    std::cout << "Enter number of years to predict: ";
    std::cin >> yearsAhead;

    // Compute historical average temperatures
    std::map<int, double> yearlyAvg;
    std::map<int, int> yearlyCount;
    for (const auto &entry : weatherEntries.entries)
    {
        int year = std::stoi(entry.utc_timestamp.substr(0, 4));
        double temp = entry.tempMap.at(Utility::stringToCC(countryCode));
        yearlyAvg[year] += temp;
        yearlyCount[year]++;
    }

    std::vector<std::pair<int, double>> historicalData;
    for (const auto &[year, sum] : yearlyAvg)
    {
        historicalData.emplace_back(year, sum / yearlyCount[year]);
    }
    std::sort(historicalData.begin(), historicalData.end());

    // Predict future temperatures
    auto predictedData = Utility::predictTemperature(weatherEntries, countryCode, yearsAhead);

    // Plot the data
    Utility::plotTemperatureLineChart(historicalData, predictedData);
}
