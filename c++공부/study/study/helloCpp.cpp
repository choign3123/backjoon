#include <iostream> //전처리 지시자. 다양한 함수들을 미리 정의해놓고 있음.
// c++로 오면서 .h가 빠지는 풍조가 생김.

/*
	c++에서는 함수를 사용하고 한다면
	반드시 그 함수의 원형을 미리 정의하여야 합니다.
	원형이 정의되어있지 않다면 그 함수를 사용할 수 없음.
*/

using namespace std;
// 얘가 없다면
// std::cout, std::endl 이렇게 쳐줘야함.
// 이게 번거로우니까 std 생략하겠다고 적어둔것.
// iostream 정의된 걸 가보면 _STD_BEGIN 이랑 _STD_END로 끝나는 걸 볼 수 있음.
// 그래서 std를 써줘야 됐던거임.

// c++ 코드에는 반드시 main의 이름을 가지고 있는 함수가 있어야한다.
int main() {

	cout << "Hello world!" << endl;
	cout << "hj 52 ";
	cout << "gn" << endl;
	// cout
	// 이 다음에 나오는 문장을 콘솔에 출력함.
	// endl은 줄바꿈 역할임.
	// 꺽쇠는 데이터의 방향(흐름)을 나타냄. hello라는 문자를 cout 너가 출력시켜줘.

	return 0;
}