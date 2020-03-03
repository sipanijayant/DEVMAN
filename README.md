# DEVMAN
A password developer and maintenance software.
This software is used to maintain passwords and developing new passwords.
The password development is made using a random generation and are saved using XOR encryption(the key for every password is unique and the key is reversed).The passwords and corresponding keys are then encrypted using RSA algorithm and then stored in a binary file.

To run the software:
We have used makefiles for the project to run.The main makefile is 'makefile.mk'.Run this file(in Linux distributions) as :make -f makefile.mk

This project was made by a team of 3:
a)Rishit Chaudhary-https://github.com/rishitc - Developed RSA encryption for our project
b)Sreyans Bothra-https://github.com/sreyansb - Developed XOR encryption,Input-Output for our project.
c)Jayant Sipani(me)-https://github.com/sipanijayant - File storage,testing

