#include <vector>
#include "WeatherData.h"
#include "WeatherAnalyzer.h"

int main()
{
    WeatherAnalyzer analyzer("data.csv");

    // Task 1: Compute candlestick data
    auto candlesticks = analyzer.computeCandlesticks("GB", "yearly");

    // Task 2: Plot candlestick data
    analyzer.plotCandlesticks(candlesticks);

    // Task 3: Filter data
    auto filteredData = analyzer.filterData(Date("1990-01-01"), Date("2000-12-31"), "FR", 0.0, 30.0);

    // Task 4: Predict temperature
    std::vector<std::pair<int, double>> predictedTemp = analyzer.predictTemperature("DE", Date("2025-01-01"), 6);
    analyzer.plotTemperatureLineChart("GB", 10);

    return 0;
}
