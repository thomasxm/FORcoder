# FORcoder
FORcoder implemented an simple obfuscation techniques on any Windows CMD Command
In paper <Orchestration of APT malware evasive manoeuvers employed for eluding anti-virus and sandbox defense>, authors used a method called FORcoding to obfuscate their CMD commands to execute whatever commands they like. Authors of the paper proposed a novel framework called Evasive Manoeuver Re-Engineering Framework (EMRF) which can effectively evade modern AV/defender engines by modifying existing N-day payloads. The EMRF contains a series of techniques include this tiny and simple FORcoding. Technique itself is simple and self-explanatory. but it is a pain to manually create your indices for the commands you want to execute and put them into a look-up table. Basically, I created this small C code to automate this process.
Both .c files can be complied with MinGW-w64 complier or visual basic. x86_64-w64-mingw32-gcc forcoder.c -o forcoder
Their usage is simple: 
obfuscator.exe "netstat /ano"
forcoder.exe "netstat /ano"
You can try more complex commands as you like. 
