#include "Candlestick.h"
#include <numeric>

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
