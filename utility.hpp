#ifndef myUtil_H
#define myUtil_H

class Log
{
private:
    int size;
    bool alter;

public:
    Log(int s, bool c)
    {
        if (s % 2 != 0)
            s++;
        this->size = s;
        this->alter = c;
    }
    void show(std::string head, std::string msg)
    {
        if (alter)
        {
            if (head.length() > this->size)
            {
                int s = floor(size / 2) - 1;
                head = head.substr(0, s) + "..." + head.substr(-s, -1);
            }
            else
                do
                {
                    head.push_back(' ');
                } while (head.length() < this->size);
            head = theedushbag::strings::uppercase(head);
        }
        std::cout << "[ " << head << " ] : " << msg << '\n';
    }
};

Log logger(7, true);

double timer(std::function<void(int, std::vector<int> &)> func, int q, std::string funcname)
{
    logger.show("running", funcname + "(" + std::to_string(q) + ")");
    time_t start = time(NULL);
    std::vector<int> store;
    func(q, store);
    time_t stop = time(NULL);
    double t = difftime(stop, start);
    logger.show("tested", funcname + "(" + std::to_string(q) + ")" + " Took " + std::to_string(t) + " seconds");
    return t;
}

void opt(std::string &str, int l, char fillchar)
{
    if (str.length() >= l)
        str = str.substr(0, l);
    else
        while (str.length() < l)
            str.push_back(fillchar);
}

void speedtest(std::vector<std::tuple<std::function<void(int, std::vector<int> &)>, std::string, int>> &data)
{
    int t;
    std::vector<double> Time;
    std::unordered_map<std::string, double> timedata;
    for (std::tuple<std::function<void(int, std::vector<int> &)>, std::string, int> &funcpair : data)
    {
        std::string funcstr = std::get<1>(funcpair) + "(" + std::to_string(std::get<2>(funcpair)) + ")";
        double timetaken = timer(std::get<0>(funcpair), std::get<2>(funcpair), std::get<1>(funcpair));
        Time.push_back(timetaken);
        timedata.insert(std::pair<std::string, double>(funcstr, timetaken));
    }
    logger.show("nb", "Compared with the slowest function");
    double highest = 0;
    for (double high : Time)
        if (high > highest)
            highest = high;
    std::string funcname;
    for (std::pair<std::string, double> data : timedata)
    {
        funcname = std::to_string(highest / data.second);
        opt(funcname, 4, '0');
        logger.show("ratio", funcname + "x | " + data.first);
    }
}

#endif