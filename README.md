"Button" class for Jellibi
===============

Contents
----------
- [JellibiButton](#JellibiButton)
- [설치](#installation)
    - [Windows](#windows) 
    - [Linux] (TBD)
    - [Mac] (TBD)
- [사용방법](#userguide)
    - [General Usage]
    - [Example](#example)
 


JellibiButton
-----------

젤리비보드는 아두이노 나노와 호환되는 보드입니다.
젤리비보드에는 상하 좌우 방향키로 사용할 수 있는 네개의 버튼이 있습니다.
버튼을 누르면 각 버튼에 연결된 Jellibi 의 포트(GPIO,General Purpose Input Output) 로 신호를 받게 됩니다. 

'JellibiButton' 클래스는 이 신호를 손쉽게 처리 할 수 있게 도와줍니다. 
더불어 버튼이 계속 눌려 있는지도 알 수 있게 도와줍니다. 

<TABLE align=center>
	<TR><TD>
	<table border=1 width=300>
	<tr bgcolor=lightgray><th> 버튼 명 </th><th>포트(핀) 번호</th></tr>
	<tr><td align=center> up </td><td align=center>A0</td></tr>
	<tr><td align=center> down </td><td align=center> A1 </td></tr>
	<tr><td align=center> right </td><td align=center> 2 </td></tr>
	<tr><td align=center> left </td><td align=center> 4 </td></tr>
	</table>
	</TD></TR>
	<TR><TH>표 1) 젤리비 마카롱 보드 버튼 핀맵 </TH></TR>
</TABLE>


설치 및 사용 방법을 아래에서 간략히 설명합니다.


 
설치
------------------

#### Windows 

아두이노를 설치 한 후 젤리비버튼과 같은 라이브러리를 다운로드하여 사용하는 방법은 여러가지가 있습니다. 
그 중 가장 간단한 방법을 설명합니다.

1. 라이브러리 다운로드하기 

> a. 젤리비버튼 깃허브(https://github.com/signaled/JellibiButton) 에서 전체 코드를 다운로드 할 수 있습니다. 
>
> b. 깃허브의 [<>Code] 탭에서 [Clone or download] 버튼을 눌러 전체 소스코드를 "zip" 파일로 다운로드 합니다.
> ![Download](http://www.robotnmore.com/matthew/jellibibutton/download_button.png)
>
>

2. 라이브러리 가져오기 

> a. 컴퓨터에서 아두이노 프로그램을 실행합니다. 
>
> b. 아두이노의 메뉴 중 "스케치 > 라이브러리 포함하기 > .ZIP 라이브러리 추가" 를 선택합니다. 
> ![Import](http://www.robotnmore.com/matthew/jellibibutton/import_ziplib.png)
>
> c. 파일 선택 창에서 다운로드 받은 JellibiButton-master.zip 을 선택합니다. 
>
> d. 다시 아두이노의 "스케치 > 라이브러리 포함하기" 를 선택하면 JellibiButton-master 항목이 메뉴에 표시됩니다. 
>![Select](http://www.robotnmore.com/matthew/jellibibutton/import_jellibibuttonclass.png)
> e. 'JellibiButton-master' 를 선택합니다.

#### Linux 
(TBD)

#### Mac (OS X)
(TBD) 


사용방법
------------

#### Method

```
void Init (int pinNumber, bool bRepeatFlag = false);
```

#####  Description 

 버튼을 초기화 하는데 사용합니다. 
    
##### Parameter 

>  **int pinNumber**
>    	버튼과 연결된 포트의 핀번호 
>    	
>  **bool bRepeatFlag**
>	true : 일정한 간격(50ms) 으로 이벤트 발생
>	false : 버튼을 눌렀을 때 이벤트 발생 

```
bool Check();
```

##### Description

버튼이 눌렸는 지 검사하여 true 를 되돌려 줍니다.


### Example
```
JellibiButton _rightButton;
JellibiButton _leftButton;
JellibiButton _downButton;
JellibiButton _upButton;

void Setup()
{ 
    Serial.begin(115200);
    _rightButton.Init(2, false);
    _leftButton.Init(4, false);
    _downButton.Init(A0, true);
    _upButton.Init(A1, true);
}

void loop() 
{
    if (_rightButton.Check()) {
        Serial.print("right 버튼 누름 \n");
    }
    if (_leftButton.Check()) {
        Serial.print("left 버튼 누름 \n");
    }
    if (_upButton.Check()) {
        Serial.print("UP 버튼 누름 \n");
    }
    if (_downButton.Check()) {
        Serial.print("Down 버튼 누름\n");
    }
}
```

