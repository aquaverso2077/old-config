#!/bin/sh

if [ -f "$userresources" ]; then
    xrdb -merge "$userresources"

fi

if [ -f "$usermodmap" ]; then
    xmodmap "$usermodmap"
fi

# start some nice programs

if [ -d /etc/X11/xinit/xinitrc.d ] ; then
 for f in /etc/X11/xinit/xinitrc.d/?* ; do
  [ -x "$f" ] && . "$f"
 done
 unset f
fi

dunst &
setxkbmap -layout us,ru -option 'grp:ctrl_shift_toggle' &
xset r rate 250 30 &
nitrogen --restore &
~/.local/bin/simplebar &
exec dwm
