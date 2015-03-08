#pragma once

#include <vector>

namespace SozLibs
{
    class Stats
    {
    private:
        Stats();

    public:
        static double Mean(std::vector<int> *);

        static double Median(std::vector<int> &);

        static std::vector<int> Mode(std::vector<int> &);

        static double StdDev(std::vector<int> *);
    };
}