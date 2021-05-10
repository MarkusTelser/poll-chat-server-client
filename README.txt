ChatServer
made by Markus Telser and Michael Nock

---RUN---:
To run program:
make
./client hostadress port and ./server port

---HELP---:
If there are appearing any weird character in the client gui, or it is flickering,
try to do this:
export NCURSES_NO_UTF8_ACS=1

if you are in a bash like shell or in csh like shell:
setenv NCURSES_NO_UTF8_ACS 1
