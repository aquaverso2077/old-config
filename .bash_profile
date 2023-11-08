[[ -f ~/.bashrc ]] && . ~/.bashrc
. "$HOME/.cargo/env"
if [ -z "$DISPLAY" ] && [ "$XDG_VTNR" -eq 1 ]; then
    exec startx
fi
