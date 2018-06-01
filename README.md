# EasyPhoneMapper

A command line program to output phone number combinations that are easier to remember. e.g. 1-800-FLOWERS.

The program accepts user phone number input via the console or through an input file to aid in batch processing.

## Usage

*EasyPhoneMapper.exe [-h|-help] [[-d] dictionaryFile] [[-i] inputFile] [[-p] prefix string]*

Where,
* **-h|help**	Displays this help text.
* **-i**     	Text file containing one phone number per line.
* **-d**     	User specified dictionary file with one word per line.
* **-p**     	The fix number to prefix a given phone number. e.g. '1-800'"

e.g.

Process a list of phone number present inside a file:

    C:\EasyPhoneMapper\> EasyPhoneMapper.exe -d dictionary.txt -i phoneNumberList.txt

If the program is invoked without arguments, the console output will be as under:

    C:\EasyPhoneMapper\> EasyPhoneMapper.exe
    Input phone number: 227
    Found "2" acceptable combinations for phone number 227
    BAT
    CAT
    Try another phone number [Y/N]?N
    C:\EasyPhoneMapper\>

*Note: All the command line arguments are optional.*

## Getting started

### Technical Overview

EasyCodeMapper is a single-threaded console application implemented in C++ within Microsoft Visual Studio IDE 2015 on Windows. It employs an iterative approach to problem solving not usually seen with problems that employ permutation logic. Every effort has been made to keep the memory requirement to a bare minimum.

The function names and variables are self-explanatory and as such the code is not heavily commented to assist in readability with ease.

Functionally, there are 3 main classes: *CDictionary*, *CGenerator* and *CEasyPhoneMapper*

*CDictionary* stores the dictionary contents inside a multi-map. So 227 as a key, may map to CAT or BAT. It also stores the map to translate the character to a number to assist with the former operation.

*CGenerator* is the heart of the program and employs an iterative logic to produce the phone number combinations. I've experimented with iterative over recursive for a change. Changing the logic to be a recursive one is very much possible without impacting other sections of the code.

*CEasyPhoneMapper* is the driver/binder/manager class that initializes the dictionary and invokes the processing functionality of the *CGenerator* class.

#### Processing specifics

* The input phone number is first sanitized to remove any space or punctuation characters viz. ;:.",'!?[]()-\{}/
* The generated combination is valid only if there are not more than two consecutive characters digits (post replace).
* The output will contain all capital characters separated with a hyphen (-) at word boundaries.

#### Assumptions
* The alpha numeric text file is not validated for errors during read time. This is because it is an internal file used by the program with the flexibility to customise if desired.
* The program expects the dictionary and the input batch file to have only one word per line. Non conformance may result in an undefined behaviour or incorrect results.

### Test execution

The unit test cases can be found inside the [Tests](https://github.com/gauritikekar/EasyPhoneMapper/tree/master/EasyPhoneMapper/Tests) folder. These test cases are executed every time on startup for a debug build.

## Deployment:

Download the latest build [here](https://github.com/gauritikekar/EasyPhoneMapper/releases).

Alternatively, you can choose to download and compile as well. The project file is Visual Studio 2015 and upwards compatible. 

### Default data

The default data files must be located inside the [Data](https://github.com/gauritikekar/EasyPhoneMapper/tree/master/EasyPhoneMapper/Data) folder that contains the program executable. These files are automatically loaded when the program is executed without any arguments. 

The program returns an error and exits if these files could not be opened. 

#### alphanum.txt
The file [alphanum.txt](https://github.com/gauritikekar/EasyPhoneMapper/blob/master/EasyPhoneMapper/Data/alphanum.txt) contains the character to digit mapping information. Alter this mapping to effect how phone number are interpreted. Since this mapping is consistent across phones, overriding of this information is not supported via a command line option.

#### dictionary.txt
The file [dictionary.txt](https://github.com/gauritikekar/EasyPhoneMapper/blob/master/EasyPhoneMapper/Data/dictionary.txt) contains the default word dictionary looked up by the program to separate known/acceptable word permutations from the generated ones.

Add or modify the file contents to enrich the vocabulary accessible to the program. Alternatively, provide a custom dictionary file using the '-d' command line option.

