#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>



class HexDataClass {
public:
    


 /// <summary>
/// Sets the value of the HexDataClass object to the specified integer number.
/// </summary>
    void setValue(int number);
   

    /// <summary>
  /// Sets the value of the HexDataClass object to the integer value represented by the specified string number in hexadecimal format.
  /// </summary>
    void setValue(std::string number);

    /// <summary>
    /// Returns the current value of the HexDataClass
    /// </summary>
    int getValue() const;

    // Returns a vector containing the hexadecimal representation of the current value of
        // the HexDataClass object, as a sequence of characters.
    std::vector<char> getHexChars() const;

    // Returns the integer value represented by the middle two hexadecimal digits of the
    // current value of the HexDataClass object.
    int getMiddle2Value() const;

    // Returns the integer value represented by the last two hexadecimal digits of the
   // current value of the HexDataClass object.
    int getLast2Value() const;
};