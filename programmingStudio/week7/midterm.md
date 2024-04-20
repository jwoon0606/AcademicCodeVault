# midterm prep

### 정적 라이브러리

- 컴파일(오브젝트 파일 생성)<br>
`gcc -c calculator.c`<br>
-> calculaotor.o<br>
<br>
- 정적라이브러리 생성<br>
`ar rv libcal.a calculator.o`<br>
-> libcal.a<br>
<br>
- object파일을 이용한 컴파일<br>
`gcc ./inc/calculator.o mycal.c -o mycal2`<br>
-> mycal2<br>
<br>
- 정적 라이브러리를 이용한 컴파일<br>
`gcc mycal.c -o mycal -I./inc -L./inc -lcal`<br>
	 -I./inc : 현재 폴더 아래 inc폴더에서 헤더파일을 찾는 옵션<br>
	 -L./inc : 현재 폴더 아래 inc폴더에서 라이브러리를 찾는 옵션<br>
	 -lcal : 정적라이브러리인 libcal.a와 링크하라는 옵션<br>

### make utility

- 구조<br>
	 target: 명령어가 수행된 결과 파일명<br>
	 dependency: 대상 파일 생성을 위해 필요한 파일<br>
	 command: 실행할 명령 문자<br>
	 macro: 코드 단순화<br>
<br>
![makefile.png](https://github.com/jwoon0606/AcademicCodeVault/blob/main/programmingStudio/week7/screenshots/makefile.png)

### Git

- vcs(version control system)의 종류<br>
	cvcs(centralized vcs)<br>
	dvcs(distributed vcs)<br>
<br>
- add<br>
	git add index.html index2.html<br>
	git add \*.*<br>
	git add \*.html<br>
<br>
- commit<br>
	git commit<br>
	git commit -m "commit msg"<br>
	git commit -am "commit msg"<br>
<br>
- git rm<br>
	untracked file 삭제: rm \<filename><br>
	로컬 디렉토리와 git 저장소 모두 삭제: git rm \<filename><br>
	git에서만 삭제, 로컬 디렉토리에는 삭제 안함: git rm --cached <br>\<filename>
<br>
- git status<br>
	untracked file상태 , staged 전 상태, commit전 상태 확인 가능<br>
<br>
- git log<br>
	cimmit history 확인 가능<br>
<br>
- git diff<br>
	커밋,워킹 디렉토리,stasing area간의 비교 가능(커밋 간의 비교도 가능)<br>
<br>
- git --amend<br>
	최종 완료한 commit 내역 수정<br>
	`git commit -m 'commit message'`<br>
	`git add new_file`<br>
	`git commit --amend`<br>
	커밋 커멘트만 수정하러면 add 과정 생략하고 하면 됨<br>
<br>
- gid revert vs reset<br>
	revert는 이전의 커밋들을 삭제하지 않고 과거 커밋을 새롭게 커밋해줌<br>
	reset은 실재로 과거 커밋까지 후의 내용들을 삭제해줌<br>
<br>
- git reset<br>
	`git reset --soft HEAD~`<br>
	~는 아래로 한 칸, <br>
	--soft로 reset하면 HEAD는 과거 커밋으로 이동하고,<br>
	최근 커밋내용들은 staging area에 add된 상태로 되어있음<br>
	그래서 그대로 커밋하면 다시 원래대로 돌아옴.<br>
	working directory도 그대로 유지됨<br>
	
	`git reset --mixed HEAD~`<br>
	--mixed 는 default 옵션이다.(안적어 줘도 됨)<br>
	--soft와 같은데 staging area에 add가 안되어있다는 차이점 있음<br>

	`git reset --hard HEAD~`<br>
	working directory에는 과거 커밋내용으로 저장되고,<br>
	staging area는 비워진다.<br>

- git clone<br>
	`git clone <remote repository url>`<br>
	`git clone <remote repository url> <new folder>`<br>
	`git clone -b <branchname> <remote repository url>`<br>

- remote repo<br>
	`git remote`<br>
	`git remote -v`: fetch 와 push 확인 가능<br>
	`git remote -h`<br>
	`git remote add origin <remote repository url>`<br>
	`git remote reomove origin`<br>
	`git remote add calculator <remote repository url>`<br>
	`git push origin master`<br>
	`git pull origin master`<br>
	`git fetch` : local repo는 그대로 두고 새로운 브랜치에 pull 하는 방식<br>
<br>
- pull vs fetch  
	pull = fetch + merge  
<br>
- branch  
	`git branch <new branch>`  
	`git branch -h` : 도움말  
	`git branch -a` : 모든 브랜치  
	`git branch`  
	`git branch -d <branchname>` : 삭제  
	`gir branch -D <branchname>` : 작업 여부와 상관 없이 삭제 가능  
  <br>
	`git checkout <branchname>` :   
	`git checkout -b <new branch>` : 새로운 브렌치 만들고 전환  
<br>
- git stash  
	`git stash`  
	`git stash save`  
	`git stash list`  
	`git stash apply [stash이름]`  
	`git stash pop` : // apply + drop  
	`git stash drop` : 일부 작업 삭제  
	`git stash clear` : 전체 작업 삭제  
<br>
- git merge  
	fast forward(--ff) : 기본값임, merge commit 생성 안함  
	no fast forward(--no--ff) : merge commit 생성함  
	--squash : merge 후 파일 상태로 변경, 다른 브랜치를 현재 브랜치에 그냥 합쳐버려서 merge commit 생성 안함, 별도 commit 해야 함, 하나의 마스터 브랜치를 유지하기 위한 목적  
<br>
- merge conflict  
	파일 수정해서 충돌 피하기  
<br>
- cherry-pick  
	커밋 전에 끼워넣어서 충돌 피하기  
<br>
- git reflog  
	모든 참조 기록 확인  
<br>
- git rebase  
	브랜치의 paraent를 바꾼다.  
	`git revbase -i` : 커밋 history 변경 가능  

### github

- git clone https://PAT@github reppo 주소  
- 개인 블로그 생성 가능  