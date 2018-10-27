cat $1 > /tmp/a

cat /tmp/a | sed -e 's/UnknownView/UnknownKeyboardAction/g' | sed -e 's/UNKNOWNVIEW/UNKNOWNKEYBOARDACTION/g' > $1
