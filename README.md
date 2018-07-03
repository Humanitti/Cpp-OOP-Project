Banking System C++ Project

목표: C++에 한걸음 다가서기

## git 명령어

* git commit -m "메시지" : 변경내역을 commit하여 버전을 생성한다. (-m 다음에 나올 인수를 메시지 취급한다.)
* git push : GitHub에 현재 변경내역을 업데이트한다.
* git pull : GitHub에 업데이트된 내역을 로컬 저장소로 가져온다.
* git commit --amend : 기존에 commit한 내용을 수정하여 다시 commit한다.
* git push --force : 충돌을 무시하고 강제로 push한다.





## 에러 발생!

  ! [rejected]        master -> master (non-fast forward)

push를 하게 되면 서버에 있는 최신 내용은 날아갈 위험이 있기 때문에 뜨는 에러 메시지다.<br/>
pull을 이용해 최신 내용을 merge한 뒤 push를 해야 한다.<br/>
conflict가 발생할 경우 소스를 수정해서 push해야 하는데 merge를 어찌저찌 하면 잘 될 것 같지만<br/>
귀찮아서 git push --force 명령어를 사용하여 강제로 push했다.(메모장 내용만 추가했는데 왜 conflict가 뜨는지도 모르겠고..)<br/>
이번 기회엔 add, commit, push, pull 정도 사용할 수 있게 된 듯.<br/>
