#ifndef __JELLIBI_BUTTON_H__
#define __JELLIBI_BUTTON_H__
/* class JellibiButton
 * 버튼과 연결된 GPIO 를 모니터링하여 아래 두가지 경우에 Check() 메서드에서 true 를 리턴하도록 구현
 * 1. 버튼을 눌렀을 때와 
 * 2. 버튼이 눌려진 상태에서 정해진 주기마다 
 * 
 * 정해진 주기 상수 : _REPEAT_INTERVAL_
 * 
 */
class JellibiButton
{
private:
  int _nPinNumber;
  int _nCurState;
    
  bool _bRepeatFlag; 
  const int _REPEAT_INTERVAL_ = 50;  
  int  _nLastRepeatTime;
  
public:
  JellibiButton();
  void Init(int nPin, bool bRepeat = false);
  bool Check();
};

#endif //__JELLIBI_BUTTON_H__
