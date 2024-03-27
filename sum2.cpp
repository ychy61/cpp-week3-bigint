#include <string>
using namespace std;

//덧셈 연산
string bigSum(string firstNum, string secondNum){
      //두 숫자 중 더 길이가 더 큰 숫자의 길이
      int maxSize;

      if (firstNum.length() > secondNum.length()){
            //첫번째 숫자가 길이가 더 크면

            //maxSize는 첫번째 숫자의 길이를 가짐
            maxSize = firstNum.length();

             //두번째 수 앞(에 작은 길이만큼 0을 넣음(계산 편의상)
            secondNum.insert(0, firstNum.length() - secondNum.length(), '0');
      }else if(firstNum.length() < secondNum.length()) {
            // 두번째 숫자가 길이가 더 크면

            //maxSize는 두번째 숫자의 길이를 가짐
            maxSize = secondNum.length();

            //첫번째 수 앞에 작은 길이만큼 0을 넣음
            firstNum.insert(0, secondNum.length() - firstNum.length(), '0');
      } else{
            //둘의 길이가 같으면
            maxSize = firstNum.length();
      }

      // 결과를 저장할 string, +1을 하는 것은 올림수가 발생할 수 있으므로 일단 +1함
      string sumResult(maxSize+1, '0');
      int carry = 0; //올림수를 저장할 변수


      //뒷자리부터 접근해야 하므로 i는 maxSize - 1의 값을 가짐
      for( int i = maxSize - 1; i >= 0; i--){

            //각 자릿수와 올림수를 더함
            //char(문자)형을 int형으로 바꾸기 위해서 0의 아스키 코드 값인 48을 뺴주면 int형을 얻을 수 있다.
            int digit = (firstNum[i] - '0') + (secondNum[i] - '0') + carry;

            //자릿수의 합이 10이 넘어가면 carry에 올림수를 저장함
            carry = digit/10;

            //결과를 저장함
            sumResult[i+1] = digit%10+'0';//0의 아스키 코드 값인 48을 더하면 char형을 얻을 수 있다.
      }

      if (carry == 1){//계산을 다했는데 올림수1이 남아있으면 0을 1로 바꿈
            sumResult.replace(0,1, "1");
      }else{//올림수가 없으면 혹시 몰라서 올림수 자리를 만들어 둔 것을 지워야함
            sumResult.erase(0, 1);
      }

      return sumResult;
}
