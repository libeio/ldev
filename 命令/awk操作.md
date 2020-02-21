
## �ο�
- [AWK�����������](https://awk.readthedocs.io/en/latest/index.html)

## awk ���˵��
- ����
    + ���ж��ı������ݽ��д���ÿ�г�Ϊһ����¼�����ö����������������ļ�������׼��������
      ���������������
- �����ṹ
  ```shell
  awk [cmd] 'BEGIN{...} pattern1{action1} pattern2{action2}...{actionx} END{...}' <�ı�>
  ```
- ����ѡ��
    + -F fs fsָ������ָ���(Ĭ�Ͽհ��ַ�)����-F:, fsҲ������������ʽ���ַ���
      ```shell
        awk -F: '{ print $NF; }' /etc/passwd
      ```
    + -v var=value ���ⲿ���� value ��Ϊ awk �ڲ����� var ���� awk
      ```shell
        VAR=10000
        echo | awk -v VARIABLE=$VAR '{ print VARIABLE }'
      ```
- ����
    + ������ 3 �����飬ÿ�����ڿ���ִ�ж�����䣬���֮��ʹ�� ; �ָ�����䰴���Ⱥ�˳��ִ�У�
        + BEGIN ���鳣���ڶ��ļ�����ɨ��֮ǰ�Ĺ����趨��������壻
        + ģʽ���������ڶ�ɨ�赽��ÿһ�У����� pattern ִ����Ӧ�Ķ�����
        + END �������ڶ�ִ�еĽ�������ܽ�ͳ�ƴ���
    + ģʽ�������� pattern ����ʡ�ԣ�Ҳ�����ж��ģʽ������䡣���ж��ģʽ�������ʱ�൱��ִ��
      `if(pattern1){ action; } else if(pattern2){ action2; } ... else{ actionx; }`
    + pattern ����������д�� `{if(pattern){action}}` �� `/pattern/{action}`����Ҫ����һЩ����(
      ���б�־��ͳ��)�Խ��к�������ʱ����ʹ��ǰ�ߣ���ֻ���м���ɨ�账��ʱ����ʹ�ú��ߡ�
    + awk ���� ' ' ��������ᵼ���������޷�ʹ����������չ��ֻ��ʹ��Ԥ�����ڲ���������ȻҲ����ʹ
     �� " " �����������Ϳ���ʹ����������չ���� awk �ĳ����Ǵ����ʽ�ı��ģ���Ԥ�����ڲ���������
     ��������Ҫ�����Բ���������������
    + 3 �����飬��������ȡ��pattern Ҳ���Խ���ʡ�ԡ�BEGIN ��� END �����ֻ��һ�����������Ϊ
      ģʽ�����鿴������:
      ```shell
       awk '{U}'                            ��{U}����ģʽ������
       awk 'U {V} W'                        ��U {V} W����ģʽ������
       awk '{U} {V} {W}'                    ��{U} {V} {W}����ģʽ������
       awk 'BEGIN{U} {V} {W}'               ��{V} {W}����ģʽ������
       awk '{U} {V} END{W}'                 ��{U} {V}����ģʽ������
       awk 'BEGIN{U} {V} {W} {X} END{Y}'    ��{V} {W} {X}����ģʽ������
      ```
- ���ñ���
  ```shell
    $0    �����������ִ�й����е�ǰ�е��ı����ݣ�
    $n    ��ǰ��¼�ĵ�n���ֶΣ�����nΪ1��ʾ��һ���ֶΣ�nΪ2��ʾ�ڶ����ֶΣ�
    FS    �ֶηָ�����Ĭ�����κοո񣩣�
    RS    ��¼�ָ�����Ĭ����һ�����з�����
    NF    ��ʾ�ֶ�������ִ�й����ж�Ӧ�ڵ�ǰ���ֶ�����
    NR    ��ʾ��¼������ִ�й����ж�Ӧ�ڵ�ǰ���кţ�
  ```
- ��¼���ֶ�
  һ�о���һ����¼��һ����¼�����ж���ֶΡ�
  ```shell
    root:x:0:0:root:/root:/bin/bash
    daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
    bin:x:2:2:bin:/bin:/usr/sbin/nologin
  ```
  �������ϼ��У���� FS=":" RS="\n", �� NF=7, RS=2
- ֧���﷨
  ```shell
    if else
    for
    do while
    while
    break
    continue
    in
    ����
  ```
  ������ʹ�� if else �Ϳ�����һ�㴦����Ҫ�� 
- ���� NF �Ĵ�ӡ
  ```shell
    print NF;    ��ӡ��ǰɨ���е��ֶ���
    print $(NF); ������չ����ӡ�� NF ���ֶε����ݣ� $(NF-1) ��ʾ�����ڶ����ֶε�����
  ```
- ���������
  ```shell
    + ~           ƥ��
    + !~          ��ƥ��
  ```
- ������ʽ
  ```shell
    ^           ��ĳ�ַ�����ʼ����
    $           ��ĳ�ַ�����������
    \<          ��ĳ�ַ�����ʼ�ĵ���
    \>          ��ĳ�ַ��������ĵ���
    .           ���ⵥ���ַ�
    *           >=0, ̰��ƥ��
    +           >=1
    ?
    []
    [^]
    ()          �ӱ��ʽ��ϣ��� /(rool)+/, ��ʾһ������ rool �����
    |
    \           ת���ַ�
    x{m}        ƥ���ظ� m �ε� x 
    x{m,}       ƥ���ظ� m ������(���� m ��)�� x���� /\(root\)\{2,\}/
    x{m, n}     ƥ���ظ����� m �Σ����� n �ε� x��ʹ�����ʱ awk ��Ҫָ�� -posix �� --re-interval ����
  ```
- ���������
  ```shell
    + -         �ӣ���
    * / %       �ˣ���������
    + - !       һԪ�ӣ������߼���
    ^           ����
    ++ --       ���ӻ���٣���Ϊǰ׺���׺
  ```
  ע��: ��������������������в������������Զ�תΪ��ֵ�����з���ֵ����Ϊ0
- ��ֵ�����
  ```shell
    =           ��ֵ
    +=          ��
    -=          ��
    *=          ��
    /=          ��
    %=          ��
    ^=          ��
  ```
- �߼������
  ```shell
    ||          ��
    &&          ��
  ```
- ��ϵ����
  ```shell
    <
    <=
    >
    >=
    !=
    ==
  ```
  ע��: > < ������Ϊ�ַ����Ƚϣ�Ҳ����������ֵ�Ƚϣ��ؼ���������������ַ����ͻ�ת��Ϊ�ַ�
  ���Ƚϡ�������Ϊ���ֲ�תΪ��ֵ�Ƚϡ��ַ����Ƚϣ�����ASCII��˳��Ƚϡ�
- ���������
  ```shell
    $           �ֶ�����
    �ո�        �ַ������ӷ�
    ?:          ��Ŀ����
    in          �������Ƿ����ĳ��ֵ
  ```
- next ��ʹ��
    + ѭ������ƥ�䣬�������next���ͻ�������ǰ��¼��ִ����һ����¼��
    + �����������жϣ�Ҳ�������еĺϲ���
- ���̿������
    + ���������ж���䣬whileѭ����䣬forѭ����䣬do...whileѭ����伸����Ҫ��䣬���÷�
      ��C��������
    + ����for��������һ�ָ�ʽ�÷�(�������)
      ```shell
        for(���� in ����)
          {������������Ϊ��}
      ```
    + ������仹���� break��continue��next��exit��
- ����Ӧ�ü�������غ���
    + awk���鲻����ǰ������Ҳ����������С;
    + ����Ԫ����0����ַ�������ʼ��������������Ķ�����
    + �ر�ע�⣬awk��������Ĭ����1��ʼ������C�������鲻ͬ��
    + ����ʹ�����ֻ��ַ���������������
    + ��������
      ```shell
        awk 'BEGIN{num[0]="apper"; num[1]="pear"; for(i=0;i<2;i++){print num[i];}}'
        awk 'BEGIN{color["red"]=1; color["green"]=2; color["blue"]=3; for(item in color) {print item, color[item];}}'
      ```
    + �ָ��ַ���������
      ```shell
        awk 'BEGIN{str="red green blue white black"; clen=split(str, color, " "); for(k=1; k<=clen; k++){print k, color[k];}}'
      ```
      ��str�Կո���������ָ�������color�����У������ӡ
    + �����Ƿ����ĳ��ֵ
      ```shell
        awk 'BEGIN{color["red"]=1; color["green"]=2; color["blue"]=3; if ("grey" in color){print "exist";}else{print "not exist";}}'
      ```
    + ɾ������ĳ��ֵ
      ```shell
        awk 'BEGIN{color["red"]=1; color["green"]=2; color["blue"]=3; if ("green" in color){delete color["green"];}; for(item in color){print item, color[item];}}'
      ```
    
## awk ��������ʾ��
- `ifconfig enp0s3 | awk 'BEGIN{FS="[[:space:]]+";} NR==2{ print $3; }'`
    ��ȡ ip ��ַ
- `awk 'BEGIN{ FS="[:/]+"; } { print $1 " " $(NF); }' /etc/passwd`
    �� : �� / ��Ϊ�ָ�������
- `awk '{ if (NR >= 5 && NR <= 10 ){ print $1; } }' /etc/passwd`
    �鿴�ļ��� 5 �е��� 10 �е�����
- `awk '/^root/{print "I am root"}/^daemon/{print "I am daemon"}{print "I am other"}' /etc/passwd`
    ��ƥ��
- `netstat -an | awk '/^tcp/{ ++s[$NF]; } END{ for (a in s) print a, s[a]; }'`
    �鿴���������е�����״̬������
- `awk 'BEGIN{ FS=":"; } { print ($0 ~ /^s/) ? $1 : "It is not match!"; }' /etc/passwd`
    �ҵ��� s ��ͷ���û�����ӡ�����û����������ӡ It is no match!
- `awk 'NR%2==1{ next; } { print $0; }' /etc/passwd`
    ��ӡż����
- `awk '/^web/{ T=$0; next; } { print T":\t"$0; }' web.txt`
    + ����¼�� web ��ͷ��T ����˼�¼��������ǰ��¼ִ����һ�У�
    + ����һ�в��� web ��ͷ����ִ�� { print T":\t"$0; }��T��֮ǰ����ı���
- `ps -ef | grep "stunnel" | awk '$0 !~ /grep/ && $8 ~ /stunnel\>/{ print $0; }'`
    �鿴�����Ƿ����
- `ps -ef | grep stunnel | awk '$0 !~ /grep/{ print $2; }' | xargs kill -9`
    ɱ��ָ������
- `ps -ef | grep xxx | awk '{ print $1; }' | xargs -I {} kill -9 {}`
    ɱ��һ������
- `free | awk '/Mem/{printf("RAM Usage: %.2f %%\n"), $3 / $2 * 100}'`
    �ڴ�ռ�ü��
- `nm test.so | cut -d" " -f3 | awk '$0 ~ /\<V2x/ && $0 !~ /url\>/{ print $0; }'`
    ƥ���Կո�ָ��ĵ� 3 ���ֶΣ��Ҹ��ֶ��� V2x ��ͷ�������� url ��β
- `awk '/^sslVersion/ || /^output/ || /^pid/ || /^cert/ || /^key/ { print "    "$0; }' test.conf`
    һ����ƥ���ļ��еĶ����
- `awk '$0 ~ /DUMP/{ print $0; }' test.log | cut -d: -f 3 | sed 's/|//g'| sed 'N;N;N;N;s/\n//g'`
    �д����ļ�
- `ls -al | grep '^-'  | awk '{ print $(NF); }' | sort -r | head -n $(($(ls -al | grep '^-' | wc -l) - 180))`
    ��ӡ��ǰĿ¼�°��涨�����ĳ������ļ������ĳ����� 180 ���ļ���ǰ����ļ�
- `ls -al './v2x/log' | grep '^-'  | awk '{ print $(NF) }' | sort -r | tail -n +161 | xargs -I {} rm -rf {}`
    ֻ������ǰĿ¼�°��涨������ǰ 160 �������ļ�
- `openssl x509 -text -noout -in rsa.crt | awk 'BEGIN{ pubkey=""; flag=0; } { if($0 ~ /\<Modulus:/){ flag=1; }else if($0 ~ /\<Exponent:/){ flag=0;}else if(flag==1){ pubkey=pubkey""$0; } } END{ print pubkey; }'| sed 's/\s*//g'`
    ��ӡ֤��Ĺ�Կ���֣����ϲ���һ���ַ���
- `find . | xargs -I {} ls -al {} | grep "^-" | awk '{ print $NF; }' | xargs -I {} file -i {} | grep "charset"`
    �鿴��ǰ·����������ͨ�ļ��ı����ʽ
- `find . | xargs -I {} ls -al {} | grep "^-" | awk '{ print $NF; }' | xargs -I {} dos2unix {}`
    ����Ŀ¼�����г����ļ�תΪ unix ��ʽ
- `sed 's/^\s*//' bookmarks.json | awk '/^\"title\"|^\"uri\"/{ print $0; }'`
    ȥ���ո������ "title" �� "url" ��ͷ����
- `awk '/Signed data/{ print $0; }' test.txt | cut -d: -f2 | sed 's/\s*//g' | awk '{ print length($0)"\n"$0; }'`
    �ҳ����� Signed data ���У��� : �ָ��������֣���ȡ�ڶ����֣�ȥ�����пո񣬴�ӡ֮��ĳ���������