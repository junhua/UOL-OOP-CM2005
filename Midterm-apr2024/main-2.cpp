#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

enum class CountryCode
{
    AT,
    BE,
    BG,
    CH,
    CZ,
    DE,
    DK,
    EE,
    ES,
    FI,
    FR,
    GB,
    GR,
    HR,
    HU,
    IE,
    IT,
    LT,
    LU,
    LV,
    NL,
    NO,
    PL,
    PT,
    RO,
    SE,
    SI,
    SK,
    UNKNOWN
};

class WeatherEntry
{
public:
    std::string utc_timestamp;
    std::map<CountryCode, double> tempMap;

    WeatherEntry() {}
    WeatherEntry(std::string timestamp, std::map<CountryCode, double> temps)
        : utc_timestamp(timestamp), tempMap(temps) {}
};

class WeatherEntries
{
public:
    WeatherEntries() {}
    WeatherEntries(std::vector<WeatherEntry> entries) : entries(entries) {}
    std::vector<WeatherEntry> entries;
};

class Candlestick
{
public:
    Candlestick(std::pair<std::string, std::vector<double>> data, double open);

    double high, low, open, close;
    std::string date;
    CountryCode cc;
};

class Utility
{
public:
    static std::vector<Candlestick> computeCandlestick(WeatherEntries entries);
    static std::string ccToString(CountryCode cc);
    static CountryCode stringToCC(std::string cc);
    static WeatherEntries readCSV(std::string filename);
    static std::vector<std::string> tokenise(std::string csvLine, char separator);
    static WeatherEntry stringsToWeatherEntry(std::vector<std::string> tokens);
    static std::vector<std::pair<int, double>> predictTemperature(const WeatherEntries &entries, const std::string &country, int yearsAhead);
    static void plotTemperatureLineChart(const std::vector<std::pair<int, double>> &historicalData, const std::vector<std::pair<int, double>> &predictedData);
};

class WeatherMain
{
public:
    WeatherMain();
    void init();
    void printMenu();
    void handleCandlestick();
    void handlePrediction();
    void plotCandlesticks(const std::vector<Candlestick> &candlesticks);
    void predictAndPlotTemperature();

private:
    WeatherEntries weatherEntries;
};

Candlestick::Candlestick(std::pair<std::string, std::vector<double>> data, double open) : open(open)
{
    const std::vector<double> &v = data.second;
    if (!v.empty())
    {
        date = data.first;
        close = std::accumulate(v.begin(), v.end(), 0.0) / v.size();
        high = *std::max_element(v.begin(), v.end());
        low = *std::min_element(v.begin(), v.end());
    }
}

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

int main()
{
    try
    {
        WeatherMain weatherMain;
        weatherMain.init();
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    return 0;
}