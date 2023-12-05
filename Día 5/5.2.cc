#include <vector>
#include <iostream>
#include <tuple>
#include <fstream>
#include <sstream>
#include <climits>

using namespace std;

long getNumbers(long thing, const vector<tuple<long, long, long>> &tuple)
{
    long soilN = thing;
    for (const auto &[dest, src, range] : tuple)
    {
        if (thing >= src && thing < src + range)
        {
            soilN = dest + (thing - src);
            break;
        }
    }
    return soilN;
}

void readMap(ifstream &file, vector<tuple<long, long, long>> &map)
{
    string line;
    while (getline(file, line) && !line.empty())
    {
        istringstream iss(line);
        long startDest, startSrc, range;
        if (iss >> startDest >> startSrc >> range)
        {
            map.push_back(make_tuple(startDest, startSrc, range));
        }
    }
}

int main()
{
    ifstream file("input.txt");
    if (!file)
    {
        cerr << "Error opening input.txt" << endl;
        return 1;
    }
    vector<tuple<long, long, long>> seedToSoil;
    vector<tuple<long, long, long>> soilToFertilizer;
    vector<tuple<long, long, long>> fertilizerToWater;
    vector<tuple<long, long, long>> waterToLight;
    vector<tuple<long, long, long>> lightToTemperature;
    vector<tuple<long, long, long>> temperatureToHumidity;
    vector<tuple<long, long, long>> humidityToLocation;
    vector<long> seeds;
    vector<long> seedsNUEVO;
    vector<long> soils;
    vector<long> fertilizers;
    vector<long> waters;
    vector<long> lights;
    vector<long> temperatures;
    vector<long> humidities;
    vector<long> locations;

    long lowest_location = LONG_MAX;
    string line;
    getline(file, line);
    istringstream seedStream(line.substr(line.find(':') + 1));
    long seed;
    while (seedStream >> seed)
    {
        seeds.push_back(seed);
    }
    getline(file, line);
    readMap(file, seedToSoil);
    readMap(file, soilToFertilizer);
    readMap(file, fertilizerToWater);
    readMap(file, waterToLight);
    readMap(file, lightToTemperature);
    readMap(file, temperatureToHumidity);
    readMap(file, humidityToLocation);

    for (long i = 0; i < seeds.size(); i += 2)
    {
        for (long j = seeds[i]; j < seeds[i] + seeds[i + 1]; ++j)
        {
            long soil = getNumbers(j, seedToSoil);
            long fertilizer = getNumbers(soil, soilToFertilizer);
            long water = getNumbers(fertilizer, fertilizerToWater);
            long light = getNumbers(water, waterToLight);
            long temperature = getNumbers(light, lightToTemperature);
            long humidity = getNumbers(temperature, temperatureToHumidity);
            long location = getNumbers(humidity, humidityToLocation);

            if (location < lowest_location)
            {
                lowest_location = location;
                cout << "Location updated to " << lowest_location << " for seed " << j << "." << endl;
            }
        }
    }

    cout << "The lowest location is " << lowest_location << "." << endl;
    return 0;
}