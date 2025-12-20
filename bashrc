if [ "$(id -u)" -eq 0 ]; then
        PS1='\[\e[95m\]\w >w< \[\e[0m\]'
else
    	PS1='\[\e[94m\]\w >w< \[\e[0m\]'
fi
