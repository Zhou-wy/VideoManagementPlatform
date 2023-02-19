//
// Created by zhouwy on 2023/2/19.
//
//
// Created by zhouwy on 2023/2/19.
//
#pragma execution_character_set("utf-8")
#include <iostream>
extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libavfilter/avfilter.h>
}

int main(int argc, char *argv[]) {

    std::cout << avcodec_configuration() << std::endl;
    std::cout << avformat_configuration() << std::endl;
    std::cout << avutil_configuration() << std::endl;
    std::cout << avfilter_configuration() << std::endl;
    return 0;
}