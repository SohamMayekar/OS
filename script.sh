echo "a)OS version, release number and kernel version"

uname -a

cat /etc/os-release

 

echo "b)top 10 processes in descending order"

ps -eo pid,ppid,cmd,%mem --sort=-%cpu | head

 

echo "c)process with highest memory usage"

ps -eo pid,ppid,cmd,%mem --sort=-%mem | head

 

echo "log_in user : $(whoami)"

echo "login name : $(logname)"

 

echo "current shell : $SHELL"

echo "home directory : $HOME"

echo "os : $OSTYPE"

 

echo "current shell setting"

set

 

echo "current working dir : $(pwd)"
