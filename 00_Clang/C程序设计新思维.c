
C ���Ա�Ǩ
  K&R -> ANSI C89 -> ISO C99 -> C11
  
���� ANSI C89 ͨ����Ϊ ANSI C ��
΢�� Visual Studio �� C++ ������Ŀǰֻ�ṩ���� C89 ���ݵ�ģʽ��

֧�� for ѭ���ڱ��������� C99 ���ֵı�׼������ VS Ҳ֧�֣�̫���ˡ�
  
POSIX ��׼
  UNIX
    POSIX
	  BSD (Berkeley Software Distribution, ������������а棬�� Mac)
	    BSD ���֤(�� clang)
	  GNU (GNU's Not UNIX���� Linux)
	    GNU �������֤(�� gcc)
		�μ� GPL ���֤(�� Glib)
 
//////////////////////////////////////// ׼������ı��뻷�� ////////////////////////////////////////
	
C ����������
  GCC
  GDB ������
  Valgrind ���ڲ��� C ����ʹ�ô���
  Gprof ��������Ч������
  Make ʹ���㲻��ֱ�ӵ��ñ�����
  Pkg-config ���ڲ��ҿ�
  Doxygen �������ɳ����ĵ�
  
����ϵͳ����
  POSIX ����ϵͳ����
  Windows ����ϵͳ����
  
�鿴һ��������߶�̬���ӿ���������Щ�⣬����������
  Cygwin: cygcheck libxx.dll
  Linux: ldd libxx.so
  Mac: otool -L libxx.dylib
  
Windows ��ʹ�� POSIX ��������Ҫʹ�� Cygwin ��
�������Ҫ���� POSIX �����������ʹ�� MinGW(Minimalist GUN for Winodws)��

ͨ�� Autotools �����������������־�������ǣ� ./configure, make, make install ��

gcc ��������
�������һ������ specific.o ���ļ������� Libbroad �⣬�� Libbroad �������� Libgeneral����ô��Ӧ�����룺
  gcc specific.o -lbroad -lgeneral

pkg-config ����һ����׼��һЩ������ڰ�װ�ɹ�ʱ����һ�� pkg-config Ŀ¼����Ŀ¼�µ��ļ��и������������ú�λ����Ϣ��
����Խ���Ŀ¼��ӵ� $PKG_CONFIG_PATH ����·���ϣ�֮�����ͨ�� pkg-config ������������ؿ����Ϣ��
  pkg-config --libs lua5.3
  pkg-config --cflags lua5.3
Ҳ������ gcc ���ʹ��
  gcc `pkg-config --libs --cflags lua5.3` -o test test.c
��Ҳ���Ա�д�Լ��� pkg-config �ļ�ʵ����ͬ����Ŀ�ġ�

����ʱ���ӿ�
һ�㽫��̬����·�������� /etc/ld.so.conf.d/ Ŀ¼���ʵ��ļ��С���ȻҲ�����ڱ�������ָ������ʵ�ֲ��������£�δ�����ԣ���
  LDADD=-Llibpath -Wl, -Rlibpath

//////////////////////////////////////// ���ԡ����Ժ��ĵ� //////////////////////////////////////// 

C++ ��������Դ������������������� C �򲻻ᣬgdb �Ե��� C �������á�

��ջ֡
ʾ��α��
  // addresses.c
  agent_address(int) {}
  get_agents() {
	 ...
	 agent_address(int);
	 ...
  }
  main() {
	 ...
	 get_agents();
	 ...
  }
ͨ�� backtrace ������Բ鿴�ó����ջ֡���£�
  #0 0x00413bbe in agent_address (agent_number=312) at addresses.c:100
  #1 0x004148b6 in get_agents() at addresses.c:163
  #2 0x00404f9b in main(argc=1,argv=0x7fffffffe278) at addresses.c:227
��ջ������ 0 ֡��֡�ź��ʮ��������һ����ַ�������������ص�ʱ�򣬳���ִ�н����������ַ����ַ�����Ǻ���������Σ��Լ���ǰִ�е���Դ�����кš�
�ܶ����������ɾ��������ջ�У���һ�����ĺ����Ķ�ջ��׷�������ϵ��

gdb ���ý�������
  b		break
  c		continue
  r		run
  l		list
  p		print

run args		��������
p verbose++		������Ϣ�������
p i=100			Ϊ������ֵ

gdb print ��ӡ���� array[20]
  p *array			// ��ӡ�׸�����
  p *array@10		// ��ӡǰ 10 ������
  
gdb ���ڶϵ�Ĳ���
  b 25 				// �� 25 �д����öϵ�
  info break		// �鿴�ϵ���Ϣ
  dis 1				// ʹ�ϵ� 1 ��Ч
  ena 1				// ʹ�ϵ� 1 ��Ч
  del 1				// ɾ���ϵ� 1
  
gdb �����鿴
  info local		// �鿴���ر�����
  info args			// �鿴�������
  disp avg			// ����ִ�й����У��� avg ����ʵʱ�۲�
  info disp			// �鿴����ʵʱ�۲�ĳ�Ա			�Ҳµģ���֪����û���������
  undisp 1			// ȡ���Ա��Ϊ 1 �ĳ�Ա�Ĺ۲�
  
gdb �Զ�ջ�Ĳ���
  bt				// ��ջ���ݣ����о��ж�ջ֡
  f 1				// �л����� 1 ֡��ջ
  up/down			// �ڶ�ջ�������ƶ�
  
gdb ����ִ�в���
  s
  n
  u
  c
  ret				// �ӵ�ǰ��������̧������������ֵ
  j 105				// ������ 105 ��
  
gdb �Զ��̵߳Ĳ���
  info threads		// ��ö��߳��б�
  thread 2			// �л����߳� 2
  
gdb Ϊ����ָ�����������㴦��
  set $vd = my_model->dataset->vector->data
  p *$vd@10
  set $ptr=&x[3]
  p *$ptr=8
  p *($ptr++)
  
ͨ�� gprof �Գ�������Ч�ʽ�������
  gcc ����ʱ CFLAGS ��� -pg ��
  gprof your_program > file
  
���� valgrind ������
  valgrind --db-attach=yes your_program			// �ڵ�һ������ĵ�ַ���е�����
  valgrind --leak-check=full your_program		// ����ڴ�й¶
  
��Ԫ���ԣ�Ϊ�Ƚ�С�����д��Ԫ����
���ɲ��ԣ�Ϊ��ȷ�ϲ�ͬ�����֮�����Эͬ���������м��ɲ���
���Կ�ܣ�Ϊÿ���������û��������в��ԣ��Լ������Ƿ�õ����������ϵͳ

CFLAGS=-DTest_operations 	// POSIX ��׼�ı�����ѡ��൱����ÿ�� .c �ļ��м��� #define Test_operations�����������ļ����е���ʱ�����á�

���Ը��ǣ�����д�Ĳ����Ƿ�ִ�е�����д�����д�����
ͨ�� gcov ������ÿ�д��뱻����ִ�еĴ���
  gcc -O0 -fprofile-arcs-ftest-coverge ...
  ��������У�ÿ��Դ�����ļ������һ�������������ļ� *.gcda �� *.gcno
  ���� `gcov *.gcda` �� *.gcda ���� stdout ��������п�ִ�д���ı�ִ�д����İٷֱȣ�������#include �������ڣ��������� *.c.cov �ļ�
  *.c.cov �ĵ�һ����չʾ����Ĳ�����ÿ����ִ���еı�ִ��Ƶ�ʣ����ҽ�û�б�ִ�е�����һ�� ##### ����ʶ��
���Խű�ʾ��
  vim makefile
  make ./coverage_test
  for i in *gcda; do gcov $i; done;
  grep -C3 '#####' *.c.gcov
  
����һ������һ��������� 3 �ַ�ʽȥ���������Ӧ�ó������£������ C����
  return -x;		// ���ش�����룬�ɵ����ߴ�������ɼ�������
  exit(-x);			// �жϳ���ʹ�õ�����ʱ���������ۼ�
  abort();			// �жϳ���ʹ�õ�����ʱ���Լ������е���

//////////////////////////////////////// �����Ŀ ////////////////////////////////////////

Autotools ��һ��Ϊ����ϵͳ�Զ��������� makefile ��ϵͳ��

���������У������Ŵ������൱�� $()�����磬echo `date` �� echo $(data) ������ͬ��Ȼ����make �� $() ���Լ��ر����;��������д makefile ʱ��Ҫ�÷����š�

ͳ�� .c �ļ����ض��е�����
grep "[;{}()]$" *.c | wc -l

�ű�ʾ��: �����е� .c �ļ���Ѱ���Է����ֿ�ͷ�ķǿ��У���ȷ�ϸ����Ƿ��� $i �֡�����У�д�� lines_with_${i} ��
for i in `seq 0 9`;
do
	grep -E '(^|[^0-9.])'$i *.c > lines_with_${i};
done

�ű�ʾ����ִ��ĳ�������Σ��������Ե�ִ�н��д���Ӧ���ļ�
for i in `seq 1 1000`;
do
	./run_program > ${i}.out;		// д��ͬһ���ļ� ./run_program >> run_outputs
done

echo �����Ҳ��һ������ֵ����������� echo $? ֮�� $? ��ֵ�ֱ��趨Ϊ echo ����ķ���ֵ�ˡ��������Ϊ��ĳ��Ŀ�Ķ����ʹ�� $?, 
��Ҫ������ֵ����һ������������ returnval=$? ��

if ������������; then
	#
fi

����������д�ǲ��Եģ���Ϊ��һ������ִ��ʧ�ܺ󲢲���Ӱ��ڶ��������ִ��
	cd junkdir
	rm -rf *
Ӧ������������
	cd junkdir && rm -rf *
������û���
	rm -f junkdir*

//////////////////////////////////////// �汾���� ////////////////////////////////////////

Git ����һС����󣬹ؼ��������ύ�������Ǿ���һ�� diff ��������һ���ύ�����һЩ�Դ�Ϊ���ߵı仯��һ���µ��ύ����Ϳ��Դ�����е���Ϣ��
������������ index ��֧�֣���¼�Դ���һ���ύ��ʼ��ע�������ı仯�б���Ҫ����;��Ϊ�˲�����һ���ύ����

�ύ���������������γ�һ������ÿ���ύ�����У����٣�һ�����ύ����

�õ�һ���汾��
	git init
	git clone https://github.com/b-k/21st-Century-Examples.git

�ͷ�һ���汾��
	rm -rf .git

����һ���ύ������Ϊ�ύ�����¼�Ŵ��ʼ�����ǰһ���ύ��Ŀǰ�Ĳ��죬���Ա����Ȳ���һЩ���죬Ȼ����ܽ��� commit��
index ��һ���仯�б���¼��������һ���ύ���ύ�ı仯�����Ĵ�������Ϊ����ʵ���ϲ���ϣ����ĿĿ¼�е�ÿ�����춼����¼������
index �Ĺؼ��������������ı仯�б������Ԫ�ء��ã�
	git add gnomes.c gnomes.h
������Щ�ļ����� index �С�������Ҫ������ index ���ļ�׷���б���͵ı仯���У�
	git add newfile
	git rm oldfile
	git mv file file
����ļ������ĸı���Ȼ�� Git ׷�ٵ������������Զ���ӵ� index �У�����ͨ�� git add changedfile ����ÿ���ļ���



�����ύ֮����ǳ��п������Ŷ�ͷ������������ʲô����������� git commit -amend a �������������ύ��������ִ����һ���ύ��

�л�����ʷ�汾
	git checkout fe9c4
���ص����ڵ�״̬����������ύ
	git checkout master

�������� git commit ������ SHA1 hash

����Ŀ¼�뵱ǰ index �Ĳ�ͬ
	git diff
����Ŀ¼����ʷ index �Ĳ�ͬ
	git diff fe9c4
��ʷ��������ʷ index �Ĳ�ͬ
	git diff 234e2a 8b90ac
	
��һЩ���ֿ��Ա���ȥʹ����Щ hash ֵ�� HEAD ����Ŀǰ���һ���ύ��Ҳ����һ����֧��ͷ������������ǣ�git �����һ�����󱨸棬ָ������һ��"�����ͷ"��
���� ~1 ��������ύ�ĸ��ύ�� -2 �����游�ύ���Դ����ơ�
	git diff HEAD~4					# ����Ŀ¼���Ĵ�֮ǰ���ύ���Ƚ�
	git checkout master~1			# �л��� master ���ϴ��ύ�汾
	git checkout master~			# ͬ��
	git diff b0897~ b0897			# b0897 �ı仯

stash
�ύ�����ǲο��㣬���󲿷ֵ� Git ��ǻ�����Щ�ο��㷢���ġ�
����������κ��ύ����������㵱ǰ�Ĺ���Ŀ¼������û�ж�Ӧ���ύ���ָ��Ļ�������ȥҲ���ԣ�������ȴ���������ˡ�
�����ص�ĳ���ύ����Ӧ�ð��Դ����һ���ύ�Ժ������Ĺ���������ĳ����Ȼ��ص��������ύ��ִ��ĳ�����������������ת���ߴ򲹶����ٴӱ���ĵط�
�ָ�����ǰ�Ĺ�����
stash �Ϳ���������������÷����£�
	git stash
	git checkout fe9c4
	git checkout master
	git stash pop
	
�������ǵķ�֧
����������Ǹ������е��ύ������һ�������󣬲��Ҷ������¼���Լ����丸����֮��� diff���������������յĽڵ㣬Ҳ������֦��ĩ�ң���һ����֧������
Ϊ��ǩ��
ϰ����һ���Ǳ�������֧��ʱ���������Ĺ��ܡ�������Ҫ�����µķ�֧���������֧���ʵ���˹��ܵ�ʱ�����ںϽ�����֧�С�
������֧�����ַ�����
	git branch newleaf
	git checkout newleaf
	git checkout -b newleaf
�鿴��ǰ������֧��
	git branch
����㵼��һ���ϵİ汾����һЩ�޸ģ�Ȼ��������µ��޸���һ���µ��ύ��������������ô��������һ��������֧(master)����������·�֧������������ķֲ�֮
������ git branch ����ᷢ���Լ����ڴ���(no branch)��û�б�ǩ�ķ�֧���ײ������⣬����ֻҪ�㴦��(no branch)����ô���� git branch -m new_branch_name ��
������շֳ��ķ�֧��

�ں�
Ϊ���ں����еķ����� newleaf �� master ֮��ı仯���л��� master ��֧Ȼ���� git merge:
	git checkout master
	git merge newleaf
���赱�������µ����Ե�ʱ�����û�ж� master ���κ��޸ģ���ô����������ڱ�ķ�֧�� diff ����Ӧ���� master ���൱�ڰѸ÷�֧�е�ÿ���ύ����仯��¼��
���˿�����ǰ�Ĳ��ţ���Ϊ"���"��
��������� master ���˸ı䣬�� git ���޷��Զ������ˡ�git �Ľ�������ǰ�����ı��ļ��޸ĳ�ͬʱ���������汾�����ӣ�����
	<<<<<<< HEAD
	// changed in master
	=======
	// changed in 3c3c3c
	>>>>>>> 3c3c3c
��ʱ�ںϾ�ͣ�����ˣ��ȴ�����ļ��ı༭��
�ںϵ�һ��������£�
	1. ���� git merge other_branch
	2. ���п��ܣ�����֪������������ĳ�ͻ
	3. �� git status �����δ�ںϵ��ļ��б�
	4. ѡ��һ���ļ����ֹ���顣��һ���ı��༭��������������ݳ�ͻ���ҵ���Ҫ�ֹ��ںϵı�ǡ������һ���ļ��������ļ�λ�ó��ֳ�ͻ��������ļ�ת�Ƶ����ʵ�
	   λ��
	5. ���� git add your_now_fixed_file
	6. �ظ� 3~5 ����ֱ�����е��ļ���δ�ںϵ��ļ������ύ��
	7. ���� git commit ��ȷ���ںϲ�����
ɾ����֧��
	git delete other_branch

Ǩ��
�������֧�ֳ��˲��Է�֧�����ö���֧�������޸Ĳ��ύ���������ύ������Ϊ abcd123������Ҫ�����з�������֧�ϵķ������ڲ��Է�֧�ϣ�Ӧ��
	git branch testing
	git rebase abcd123
�������е� abcd123 �ı仯��������֧�������ˣ���ͺ���������֧ʵ�����Ǵ�����ύǨ�Ʒֻ�������һ���������Ǹտ�ʼ�Ǹ��ύ��
����֧����֧Ǩ�� diff������֧����֧�ں� diff ��

Զ�̰汾��
��İ汾����һ��Զ�̵��б�ָ����������йصĴ���ڱ𴦵İ汾�⡣
�����ͨ�� git clone �õ���İ汾�⣬��ô��������¡���Ǹ��汾��ͱ�����Ϊ origin��
�� git pull origin master ����ȡԶ�̱仯����������һ�����ںϽ����㵱ǰ�İ汾�⡣
�෴�Ķ����� push �������㵱ǰ���ύ������Զ�˰汾�� git push origin bbranch��

�ǳ��п��ܣ�����������ı仯ʱ��Ӧ��������ķ�֧�ĸı䵽Զ�̷�֧�����Ǹ����������ǣ��Ǿ������ͬ�»�û��ʲô�����������һ���ǿ��ʽ���ں�һ����˵��Ҫ
�˵ĸ�Ԥ����� git ������ֻ�п��ʽ�����͡���ô��ôȷ�����������һ������أ�
	1. ���� git pull origin �Եõ��Դ����ϴε��������ı仯
	2. ��ǰ�潲���ķ�ʽ�ֹ��ں�
	3. ���� git commit -a -m "dealt with merges"
	4. ���� git push origin bbranch
	
������Խ��֧�������в�ͬ��֧֮����ύ��ʹ��ð�ŷָ�� source:destination ��֧���ֶԡ�
	git pull origin new_changes:master			// Զ�� new_changes merge ������ master
	git push origin my_fixes:version2			// ���ط�֧ my_fixes merge ��Զ��һ���µķ�֧ version2
	git push origin :prune_me					// ɾ��Զ�˷�֧ prune_me
	git pull origin new_changes:				// Pull to no branch; create a commit named FETCH_HEAD

//////////////////////////////////////// �������á��﷨ ////////////////////////////////////////

�������͵ĺ꣬���ڶ���ʧ��ʱ���᷵�أ�
#define Testclaim(assertion, returnval) if (!(assertion))		\
		{ fprintf(stderr, #assertion " failed to be true.		\
		Returning " #returnval "\n"); return returnval; }
int do_thing() {
	int x, y;
	...
	Testclaim(x == y, -1);
	...
	return 0;
}

//////////////////////////////////////// ���õĽṹ ////////////////////////////////////////

�ɱ������
һ�����ڴ������ĺ�
	char error_mode;
	FILE *error_log;
	#define Stopif(assertion, error_action, ...) {					\
		if (assertion) {											\
			fprintf(error_log ? error_log : stderr, __VA_ARGS__);	\
			fprintf(error_log ? error_log : stderr, "\n");			\
			if (error_mode == 's') 	abort();						\
			else					{ error_action; }				\
		} }
	// sample usage
	Stopif(x < 0 || x > 1, return -1, "x has value %g, "
						"but it should be between zero and one.", x)

��ȫ��ֹ���б�
	double sum_array(double in[]) {
		double out = 0;
		for (int i = 0; !isnan(int[i]); i++) out += in[i];
		return out;
	}
	#define sum(...) sum_array((double[]){__VA_ARGS__, NAN})
	
	#define Foreach_string(iterator, ...)	\
		for (char **iterator = (char*[]){ __VA_ARGS__, NULL }; *iterator; iterator++)
	Foreach_string(i, "yarn", "thread", "rope");
		printf("%s\n", *i);