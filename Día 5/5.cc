#include <vector>
#include <utility>
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

    for (long seed : seeds)
    {
        long soil = getNumbers(seed, seedToSoil);
        soils.push_back(soil);
        //cout << "Seed number " << seed << " corresponds to soil number " << soil << "." << endl;
    }

    for (long soil : soils)
    {
        long fertilizer = getNumbers(soil, soilToFertilizer);
        fertilizers.push_back(fertilizer);
        //cout << "Soil number " << soil << " corresponds to fertilizer number " << fertilizer << "." << endl;
    }

    for (long fertilizer : fertilizers)
    {
        long water = getNumbers(fertilizer, fertilizerToWater);
        waters.push_back(water);
        //cout << "Fertilizer number " << fertilizer << " corresponds to water number " << water << "." << endl;
    }

    for (long water : waters)
    {
        long light = getNumbers(water, waterToLight);
        lights.push_back(light);
        //cout << "Water number " << water << " corresponds to light number " << light << "." << endl;
    }

    for (long light : lights)
    {
        long temperature = getNumbers(light, lightToTemperature);
        temperatures.push_back(temperature);
        //cout << "Light number " << light << " corresponds to temperature number " << temperature << "." << endl;
    }

    for (long temperature : temperatures)
    {
        long humidity = getNumbers(temperature, temperatureToHumidity);
        humidities.push_back(humidity);
        //cout << "Temperature number " << temperature << " corresponds to humidity number " << humidity << "." << endl;
    }

    for (long humidity : humidities)
    {
        long location = getNumbers(humidity, humidityToLocation);
        locations.push_back(location);
        //cout << "Humidity number " << humidity << " corresponds to location number " << location << "." << endl;
        if (location < lowest_location)
        {
            lowest_location = location;
        }
    }

    cout << "The lowest location is " << lowest_location << "." << endl;

    return 0;
}