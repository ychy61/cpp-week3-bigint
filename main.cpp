#include <iostream>
#include <string>
using namespace std;

string bigSum(string firstNum, string secondNum); // 덧셈 연산 함수
string bigSub(string firstNum, string secondNum); // 뺄셈 연산 함수

int main(){
      //첫번째 수와 두번쨰 수의 값을 저장할 변수
      string firstNum;
      string secondNum;

      //첫번째 수와 두번째 수를 입력 받음
      cout << "First number  >> ";
      cin >> firstNum;

      cout << "Second number >> ";
      cin >> secondNum;

      //덧셈 결과 출력
      string sumResult = bigSum(firstNum, secondNum);
      cout << "Sum           >> "<< sumResult<<endl;

      //뺄셈 결과 출력
      string subResult = bigSub(firstNum, secondNum);
      cout << "Sub           >> "<< subResult<<endl;

      return 0;
}