#include <iostream>
#include <chrono>
#include<ctime>
#include<unistd.h>
#include<ratio>
int main(){
    auto start = std::chrono::system_clock::now();
    std::chrono::duration<int> du_1(3600);
    //std::chrono::duration<float,std::chrono::minutes> du2(60);
    std::cout << du_1.count() << "ms in 1h" << std::endl;



    // while(true){
    //     auto end = std::chrono::system_clock::now();
    //     std::time_t current_time_t = std::chrono::system_clock::to_time_t(start);
    //     std::time_t current_time_t_1 = std::chrono::system_clock::to_time_t(end);
        
    //     std::cout  << std::ctime(&current_time_t)<<std::endl;
    //     std::cout  << std::ctime(&current_time_t_1)<<std::endl;
    //     sleep(1);
        
    // }
    
    std::time_t current_time_t = std::chrono::system_clock::to_time_t(start);
    std::chrono::system_clock::time_point tp_epoch=
    std::chrono::system_clock::from_time_t(current_time_t);    // epoch value
  
    std::chrono::time_point <std::chrono::system_clock,std::chrono::duration<int>> 
    tp_seconds (std::chrono::duration<int>(1));
    
    std::chrono::system_clock::time_point tp (tp_seconds);
    
    std::cout << "1 second since system_clock epoch = ";
    std::cout << tp.time_since_epoch().count();
    std::cout << " system_clock periods." << std::endl;
    // display time_point:
    std::time_t tt = std::chrono::system_clock::to_time_t(tp);
    std::cout << "time_point tp is: " << std::ctime(&tt);

    
    //std::time_t now = std::time(nullptr);
    //获取当前时间值

    std::tm timeinfo = {};  // 初始化为0
    timeinfo.tm_year = 2022 - 1900;  // 年份，需要减去1900
    timeinfo.tm_mon = 3 - 1;  // 月份，从0开始，所以需要减1
    timeinfo.tm_mday = 1;  // 日期
    timeinfo.tm_hour = 12;  // 小时
    timeinfo.tm_min = 0;  // 分钟
    timeinfo.tm_sec = 0;  // 秒钟

    std::time_t t = std::mktime(&timeinfo);

    
    
    return 0;
}