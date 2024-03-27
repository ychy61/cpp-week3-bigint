#include <string>
using namespace std;

// 두번째 숫자가 더 크면 true를 반환하는 함수
bool bigger(int maxSize, string firstNum, string secondNum){
      for (int i = 0; i < maxSize; ++i) { //앞에서부터 비교
            if (firstNum[i] < secondNum[i]) {
                  return true;
            }
      }
      return false;
}

// 빌림이 발생하는지 확인하는 함수(발생하면 borrowNum 값을 1로하고, digit에 10을 더함)
int borrow(int& borrowNum, int digit) {
    if (digit < 0) {
        digit += 10; // 자릿수에서 빌림을 받음
        borrowNum = 1; // 다음 자릿수에서 빌림을 하기 위해 borrow를 1로 설정
    } else {
        borrowNum = 0; // 빌림이 필요 없음
    }
    return digit;
}

// 문자열(결과)에서 0을 지우는 함수
string eraseZeros(string& resultNum){
      int count;
      while ((count = resultNum.find('0')) != string::npos) {
            //찾고자 하는 값이 문자열에 없으면 find 함수는 string::npos 반환하므로

            resultNum.erase(count, 1);
      }

      //만약 값이 0일 경우에는
      if(resultNum.length() == 0){
            resultNum.append("0");
      }
}


// 뺄셈 연산
string bigSub(string firstNum, string secondNum) {
      //두 숫자 중 더 길이가 더 큰 숫자의 길이
      int maxSize;

      if (firstNum.length() > secondNum.length()){
            //첫번째 숫자가 길이가 더 크면

            //maxSize는 첫번째 숫자의 길이를 가짐
            maxSize = firstNum.length();

            //두번째 수 앞(idx=0)에 작은 길이만큼 0을 넣음(계산 편의상)
            secondNum.insert(0, firstNum.length() - secondNum.length(), '0');

      }else if(firstNum.length() < secondNum.length()) {
            // 두번째 숫자가 길이가 더 크면

            //maxSize는 두번째 숫자의 길이를 가짐
            maxSize = secondNum.length();

            //첫번째 수 앞(idx=0)에 작은 길이만큼 0을 넣음(계산 편의상)
            firstNum.insert(0, secondNum.length() - firstNum.length(), '0');
      } else{
            //둘의 길이가 같으면 첫번째 수의 길이를 가지게 함
            maxSize = firstNum.length();
      }

      string subResult(maxSize, '0'); // 결과를 저장할 string
      int borrowNum = 0; // 빌림수를 저장할 변수

      //첫번째 수가 두번째 수보다 크거나 같은 경우
      if(bigger(maxSize,firstNum, secondNum) == false){

            // 뒷자리부터 접근해야 하므로 i는 maxSize - 1의 값을 가짐
            for (int i = maxSize - 1; i >= 0; i--) {

                  // 각 자릿수에서 뺄셈 수행
                  int digit = (firstNum[i] - '0') - (secondNum[i] - '0') - borrowNum;

                  // 빌림이 필요한지 확인
                  digit = borrow(borrowNum, digit);

                  // 결과를 저장
                  subResult[i] = digit + '0'; // 문자로 변환하여 저장
            }

            // 결과에서 앞에 붙은 0 제거
            eraseZeros(subResult);
            return subResult;
      }

      //두번째 수가 첫번째 수보다 큰 경우
      if (bigger(maxSize, firstNum, secondNum) == true){
            for (int i = maxSize - 1; i >= 0; i--) {
                  int digit = (secondNum[i] - '0') - (firstNum[i] - '0') - borrowNum;
                  digit = borrow(borrowNum, digit);
                  subResult[i] = digit + '0';

            }

            eraseZeros(subResult);
            // 앞에 - 추가 (무조건 음수이므로)
            subResult.insert(0, "-");
            return subResult;
      }

}