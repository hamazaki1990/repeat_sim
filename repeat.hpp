#pragma once
#include <vector>
#include <iostream>

class CRepeat
{
    private:
    unsigned int repeat_id;
    std::vector<std::vector<int>> repeat_seq;

    public:
    CRepeat(unsigned int n, std::vector<std::vector<int>> v);
    CRepeat(unsigned int n, unsigned int initialCN, std::vector<int> monomer);
/*
    CRepeat(const CRepeat & crepeat);
*/

    unsigned int GetRepeatId();
    unsigned int GetCopynumber();
    std::vector<std::vector<int>> GetRepeatSeq();
    std::vector<int> GetRepeatMonomer(unsigned int i);
    std::vector<std::vector<int>> GetRepeatSlice(unsigned int i, unsigned int j);
    void SetRepeatId(unsigned int n);
    void SetRepeatSeq(std::vector<std::vector<int>> v);
    void SetRepeatMonomer(unsigned int i, std::vector<int> monomer);
    std::vector<std::vector<int>> GetMutatedSeq(unsigned int i, std::vector<int> monomer);
    std::vector<std::vector<int>> GetConvertedSeq(unsigned int i, std::vector<std::vector<int>> v);
    std::vector<std::vector<int>> GetInsertedSeq(unsigned int i, std::vector<std::vector<int>> v);
    std::vector<std::vector<int>> GetDeletedSeq(unsigned int i, unsigned int j);
    std::vector<std::vector<int>> GetSDedSeq(unsigned int i, unsigned int j);

    void SetMutatedSeq(unsigned int i, std::vector<int> monomer);
    void SetConvertedSeq(unsigned int i, std::vector<std::vector<int>> v);
    void SetInsertedSeq(unsigned int i, std::vector<std::vector<int>> v);
    void SetDeletedSeq(unsigned int i, unsigned int j);
    void SetSDedSeq(unsigned int i, unsigned int j);

};
