# FORcoder
![FORcoder3](https://user-images.githubusercontent.com/44269971/229361148-c27c8fa7-b547-47be-be67-3b48d52048dc.PNG)

FORcoder implemented an simple obfuscation technique that works on any Windows CMD Command environment
In paper [Orchestration of APT malware evasive manoeuvers employed for eluding anti-virus and sandbox defense](https://www.sciencedirect.com/science/article/pii/S0167404822000268), Authors of the paper proposed a novel framework called Evasive Manoeuver Re-Engineering Framework (EMRF) which can effectively evade modern AV/defender engines by modifying existing N-day payloads. The EMRF contains a series of techniques include this tiny and simple FORcoding. Authors used a static FORcoding to obfuscate their CMD commands to execute whatever commands they like. 

FORcoding technique itself is simple and self-explanatory. However, it is a pain to manually create your indices for the commands you want to execute and put them into a look-up table. It is a laborious task to do it each time you want to execute a command obfuscated. 

Basically, I created this small C code to automate this process. The code could automatically create the array of indices and 'unique' character sets for you. You can tweak the commands you want to execute based on your specific needs, the code will serve the obfuscated code on a silver platter to you. Also, the picking of unique string from left to right is predictable. So, I modofied the original algorithm and made it a bit more unpredictable. The algorithm now generates a shuffled unique string that not necessarily pick the unique character from left to right. It's now called *pseudo random or dynamic FORcoding.* 

## Compilation: 
Both .c files can be complied with MinGW-w64 complier or visual basic. 
```
x86_64-w64-mingw32-gcc forcoder.c -o forcoder
```
The compiled version will run on Windows and Linux. But it is designed for CMD commands, so why Linux? 

## Usage is simple: 
```
- obfuscator.exe "netstat /ano"
- forcoder.exe "netstat /ano"
You can try more complex commands as you like. 
```

## Usage example:
Some usage examples on the command netstat:

![FORcoder](https://user-images.githubusercontent.com/44269971/229361204-7de5edc2-c6e6-4450-8653-984f4603e587.PNG)
![FORcoder_2](https://user-images.githubusercontent.com/44269971/229361210-fdcb58f7-3748-4367-b78d-60f8946e2d96.PNG)
![dynamic_FORcoder](https://user-images.githubusercontent.com/44269971/229361212-38d6bd92-8563-4d84-b079-bbf246871733.PNG)

## Thanks
Thanks to Edinburgh Napier University and its academic community

## License
GNU General Public License Version 3
Free to use
