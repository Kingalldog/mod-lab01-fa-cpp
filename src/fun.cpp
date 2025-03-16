// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    int ans = 0;
    bool flag = true;
    bool cond = false;
    size_t i = 0;
    while (str[i] != '\0') {
    if (str[i] == ' ') {
        ans += (flag * cond);
        flag = true;
        cond = false;
    } else{
        if (str[i] != ' ') cond = true;
        if ('0' <= str[i] && str[i] <= '9') flag = false;
    }
    ++i;
}
ans += (flag * cond);
return ans;
}

unsigned int faStr2(const char *str) {
    int ans = 0;
    bool flag = false;
    bool cond = true;
    size_t i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            ans += (flag * cond);
            flag = false;
            cond = true;
        }
        else {
            if (flag == false && cond == true && 'A' <= str[i] && str[i] <= 'Z') {
                flag = true;
            }
            else if (flag == false && cond == true){
                cond = false;
            }
            else if (cond == true && (str[i] < 'a' || 'z' < str[i])) {
                cond = false;
            }
        }
        ++i;
    }
    ans += (flag * cond);
    return ans;
}

unsigned int faStr3(const char *str) {
    int ans = 0;
    int word_len = 0;
    int word_cnt = 0;
    size_t i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            ans += word_len;
            word_cnt += (word_len > 0);
            word_len = 0;
        }
        else {
            if (str[i] != ' ') word_len++;
        }
        ++i;
    }
    ans += word_len;
    word_cnt += (word_len > 0);
    return ans / word_cnt + (ans % word_cnt >= (word_cnt + 1) / 2);
}
