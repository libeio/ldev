
@echo off
REM Function:	search a specified DirectoryName in the current directory tree
REM Usage:		searchDir.bat DirectoryName
REM Attention:	run the script with appropriate permissions

REM ����˵�������ּ�����ϲ���������ע�ͣ���������֮ǰ��Ҫɾ����
REM bat �ű���ĿǰΪֹ��û�з�����ôʹ�ú�����������ʱ���޷�ʹ�õݹ�������Ŀ¼������
REM �����������ʹ�õݹ飬���Ǻ���û�з��ֶ�ջ�Ĵ����������������pop push�ȣ������Ծ������Ŀ¼������Ϻ��ٷ��أ���Ȼ��Ҫ�ص���Ŀ¼�µĵ�һ��Ŀ¼
REM ��֮��bat �ű�̫��������
REM ���� Pushed Poped

if "%1" == "" (echo parameter error & goto EXIT)

title search the directory "%1"

for /D /R "%CD%" %%B in (*) do (
	if /I %%~nxB == %1 (
		echo %%B
	)
)

:EXIT
title  %ComSpec%
@echo on
@pause