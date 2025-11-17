#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <mutex>
namespace Tools
{
    class Logger
    {
    public:
        enum Level
        {
            INFO,
            WARNING,
            ERROR
        };

        static Logger &get()
        {
            static Logger instance;
            return instance;
        }

        void log(Level level, const std::string &msg)
        {
            std::lock_guard<std::mutex> lock(mu);

            std::string prefix = levelToString(level);
            std::string time = currentTime();

            // Console
            std::cout << "[" << time << "] [" << prefix << "] " << msg << std::endl;

            // File
            if (file.is_open())
                file << "[" << time << "] [" << prefix << "] " << msg << "\n";
        }

    private:
        std::ofstream file;
        std::mutex mu;

        Logger()
        {
            {
                char filename[64];
                std::time_t now = std::time(nullptr);
#ifdef _WIN32
                std::tm tm;
                localtime_s(&tm, &now);
                std::strftime(filename, sizeof(filename), "app_%Y-%m-%d_%H.log", &tm);
#else
                std::tm tm;
                localtime_r(&now, &tm);
                std::strftime(filename, sizeof(filename), "app_%Y-%m-%d_%H.log", &tm);
#endif
                file.open(filename, std::ios::app);
            }
        }

        std::string levelToString(Level l)
        {
            switch (l)
            {
            case INFO:
                return "INFO";
            case WARNING:
                return "WARNING";
            case ERROR:
                return "ERROR";
            }
            return "UNKNOWN";
        }

        std::string currentTime()
        {
            std::time_t now = time(nullptr);
            char buf[32];
#ifdef _WIN32
            ctime_s(buf, sizeof(buf), &now);
#else
            std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
#endif
            return buf;
        }
    };
} // namespace Utility