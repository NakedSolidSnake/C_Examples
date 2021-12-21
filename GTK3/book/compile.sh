#!/bin/bash

CFLAGS = -g0 -O0

src=("02-buttons" \
     "03-container_vbox" \
     "04-container_hbox" \
     "05-container_horizontal_pane" \
     "06-container_vertical_pane" \
     "07-container_tables" \
     "08-container_fixed" \
     "09-container_expanders" \
     "10-handle_boxes" \
     "11-container_notebook" \
     "12-events_boxes" \
     "13-toogle_buttons" \ 
     "14-checkbuttons" \
     "15-radiobuttons" \
     "16-entries" \ 
     "17-spinbuttons" \
     "18-scales" \
     "19-colorbuttons" \
     "20-filechooserbuttons" \
     "21-fontbuttons" \ 
     "22-dialogs"
     "23-form_dialog" \ 
     "24-message_dialog" \ 
     "25-about_dialog" \
     "26-savefile" \
     "27-createfolder" \ 
     "28-multiple_files" \ 
     "29-colorselection" \ 
     "30-fontselection" \ 
     "31-assistant") 



for app in ${src[@]}; do
    echo "Compiling $app"
    gcc -g3 -o ${app}.out ${app}.c $(pkg-config gtk+-3.0 --cflags --libs)
done