
#include <vector>

template<typename T>
class Vec: public std::vector<T>{
public:
  using std::vector<T>::vector; /*vectorのコンストラクタ郡を使用*/
  T& operator[](int i)
      {return std::vector<T>::at(i);} /*範囲チェック*/
  const T& operator[](int i) const
      {return std::vector<T>::at(i);} /*constオブジェクトの範囲チェック*/
};

/*
使用時はmain関数自体をtry-catchにする

try {
    list.push_back(2);
    list[list.size()] = 100;
}
catch(out_of_range){
    std::cout << "range error \n" << std::endl;

}
*/
