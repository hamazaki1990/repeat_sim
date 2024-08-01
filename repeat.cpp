#include "repeat.hpp"

CRepeat::CRepeat(unsigned int n, std::vector<std::vector<int>> v)
{
    repeat_id = n;
    repeat_seq = v;
}

CRepeat::CRepeat(unsigned int n, unsigned int initialCN, std::vector<int> monomer)
{
    repeat_id = n;
    std::vector<std::vector<int>> v(initialCN, monomer);
    repeat_seq = v;
}

/*
CRepeat::CRepeat(const CRepeat & crepeat)
{
    repeat_id = crepeat.repeat_id;
    copynumber = crepeat.copynumber;
}
*/

unsigned int CRepeat::GetRepeatId()
{
    return repeat_id;
}

unsigned int CRepeat::GetCopynumber()
{
    return repeat_seq.size();
}


std::vector<std::vector<int>> CRepeat::GetRepeatSeq()
{
    return repeat_seq;
}

std::vector<int> CRepeat::GetRepeatMonomer(unsigned int i)
{
    return repeat_seq.at(i);
}

std::vector<std::vector<int>> CRepeat::GetRepeatSlice(unsigned int i, unsigned int j)
{
    try{
        repeat_seq.at(i);
        repeat_seq.at(j);
    }
    catch(std::out_of_range){
        std::cout << "range error in slicing" << std::endl;
    }
    std::vector<std::vector<int>> v2(repeat_seq.begin() + i, repeat_seq.begin() + j + 1);
    return v2;
}

void CRepeat::SetRepeatId(unsigned int n)
{
    repeat_id = n;
}


void CRepeat::SetRepeatSeq(std::vector<std::vector<int>> v)
{
    repeat_seq = v;
}

void CRepeat::SetRepeatMonomer(unsigned int i, std::vector<int> monomer)
{
    repeat_seq.at(i) = monomer;
}

std::vector<std::vector<int>> CRepeat::GetMutatedSeq(unsigned int i, std::vector<int> monomer)
{
    std::vector<std::vector<int>> v2(repeat_seq);
    v2.at(i) = monomer;
    return v2;
}


std::vector<std::vector<int>> CRepeat::GetInsertedSeq(unsigned int i, std::vector<std::vector<int>> v)
{
    try
    {
        repeat_seq.at(i-1);
    }
    catch (std::out_of_range)
    {
        std::cout << "range error in inserting" << std::endl;
    }
    std::vector<std::vector<int>> v2(repeat_seq);
    v2.insert(v2.begin() + i, v.begin(), v.end());
    return v2;


}


std::vector<std::vector<int>>  CRepeat::GetDeletedSeq(unsigned int i, unsigned int j)
{
    try
    {
        repeat_seq.at(i);
        repeat_seq.at(j);
    }
    catch (std::out_of_range)
    {
        std::cout << "range error in deleting" << std::endl;
    }
    std::vector<std::vector<int>> v2(repeat_seq);
    v2.erase(v2.begin() + i, v2.begin() + j + 1);
    return v2;
}


std::vector<std::vector<int>> CRepeat::GetConvertedSeq(unsigned int i, std::vector<std::vector<int>> v)
{
    try
    {
        repeat_seq.at(i);
        repeat_seq.at(i + v.size() - 1);
    }
    catch (std::out_of_range)
    {
        std::cout << "range error in converting" << std::endl;
    }
    std::vector<std::vector<int>> v2(repeat_seq);
    for (int k = 0; k < v.size() - 1; i++){
        v2.at(i + k) = v.at(k);
    }
    return v2;
}


std::vector<std::vector<int>>  CRepeat::GetSDedSeq(unsigned int i, unsigned int j)
{
    try
    {
        repeat_seq.at(i);
        repeat_seq.at(j);
    }
    catch (std::out_of_range)
    {
        std::cout << "range error in duplicating" << std::endl;
    }
    std::vector<std::vector<int>> v2(repeat_seq);
    v2.insert(v2.begin()+i, repeat_seq.begin() + i, repeat_seq.begin() + j);
    return v2;
}


void CRepeat::SetMutatedSeq(unsigned int i, std::vector<int> monomer)
{
    std::vector<std::vector<int>> v2(repeat_seq);
    v2.at(i) = monomer;
    repeat_seq = v2;
}


void CRepeat::SetInsertedSeq(unsigned int i, std::vector<std::vector<int>> v)
{
    try
    {
        repeat_seq.at(i-1);
    }
    catch (std::out_of_range)
    {
        std::cout << "range error in inserting" << std::endl;
    }
    std::vector<std::vector<int>> v2(repeat_seq);
    v2.insert(v2.begin() + i, v.begin(), v.end());
    repeat_seq = v2;
}


void CRepeat::SetDeletedSeq(unsigned int i, unsigned int j)
{
    try
    {
        repeat_seq.at(i);
        repeat_seq.at(j);
    }
    catch (std::out_of_range)
    {
        std::cout << "range error in deleting" << std::endl;
    }
    std::vector<std::vector<int>> v2(repeat_seq);
    v2.erase(v2.begin() + i, v2.begin() + j + 1);
    repeat_seq = v2;
}


void CRepeat::SetConvertedSeq(unsigned int i, std::vector<std::vector<int>> v)
{
    try
    {
        repeat_seq.at(i);
        repeat_seq.at(i + v.size() - 1);
    }
    catch (std::out_of_range)
    {
        std::cout << "range error in converting" << std::endl;
    }
    std::vector<std::vector<int>> v2(repeat_seq);
    for (int k = 0; k < v.size() - 1; i++){
        v2.at(i + k) = v.at(k);
    }
    repeat_seq = v2;
}


void CRepeat::SetSDedSeq(unsigned int i, unsigned int j)
{
    try
    {
        repeat_seq.at(i);
        repeat_seq.at(j);
    }
    catch (std::out_of_range)
    {
        std::cout << "range error in duplicating" << std::endl;
    }
    std::vector<std::vector<int>> v2(repeat_seq);
    v2.insert(v2.begin()+i, repeat_seq.begin() + i, repeat_seq.begin() + j);
    repeat_seq = v2;
}


/*
void CRepeat::CombineRepeatSlice(std::vector<std::vector<int>> former, std::vector<std::vector<int>> latter);
*/
/*
std::random_device rd;
std::mt19937 gen(rd());

std::uniform_real_distribution<> dist(0.0, 1.0);
*/
