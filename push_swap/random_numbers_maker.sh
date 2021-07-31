#!/bin/bash
esc="\033"
greenf="${esc}[32m"
redf="${esc}[31m"
reset="${esc}[0m"

if [ $# != 3 ]; then exit 1; fi
# 랜덤 번호 생성 횟수 조절.
for ((i=0;i<=10;i++)); do
	# ./random_numbers 개수 [최소값] [최대값]
	arg=$(./random_numbers $1 $2 $3)
	cmd=$(./push_swap ${arg})
	rst=$(echo ${cmd} | sed "s/ /\n/g" | ./checker_Mac ${arg})
	nbr=$(echo ${cmd} | sed "s/ /\n/g" | wc -l)
	#if [ rst == "KO" ]; then echo "${arg} ${rst} ${nbr} \n"
	echo "${arg} ${rst} ${nbr} \n"
	#if [ "${cmd}" == "KO" ] || [ ${nbr} > 12 ];
done