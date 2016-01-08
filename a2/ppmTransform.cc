#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

// struct to store each pixel
struct Pixel {
    unsigned int r;  // value for red
    unsigned int g;  // value or green
    unsigned int b;  // value for blue
};

// struct to store information and array
struct PpmArray {
    int size;      // number of pixels the array currently holds
    int capacity;  // number of pixels the array could hold, given current
                   // memory allocation to pixels
    int width;     // width of image
    int height;    // height of image
    Pixel *pixels;
};

// valid or not
int valid = 2;

// the number of number
int m3 = 0;

// define a pixel array
PpmArray readin;

// use reference to represent each content of ppmarray
int &indexc = readin.capacity;


int &indexs = readin.size;


int &indexw = readin.width;


int &indexh = readin.height;

// the horizontal flip function
void flipHorizontal(PpmArray &ppm);
void flipHorizontal(PpmArray &ppm){
    Pixel *newp = new Pixel[ppm.size];
    
    for (int i = 0; i < ppm.height; i++){
        for(int j = 0; j < ppm.width; j++){
            newp[i * ppm.width + j] = ppm.pixels[ppm.width * i + ppm.width - 1 - j];
        } // for
    } // for
    delete [] ppm.pixels;
    ppm.pixels = newp;
} // FlipHorizontal

// the rotate function
void rotate(PpmArray &ppm);
void rotate(PpmArray &ppm){
    Pixel *newp = new Pixel[ppm.size];
    
    for (int i = 0; i < ppm.width; i++){
        for(int j = 0; j < ppm.height; j++){
            newp[i * ppm.height + j] = ppm.pixels[ppm.width * (ppm.height - j - 1) + i];
        } // for
    } // for
    
    int temp = ppm.width;
    ppm.width = ppm.height;
    ppm.height = temp;
    delete [] ppm.pixels;
    ppm.pixels = newp;
} // Rotate

// the sepia function
void sepia(PpmArray &ppm);
void sepia(PpmArray &ppm){
    int red;
    int green;
    int blue;
    for (int i = 0; i < ppm.width*ppm.height; ++i)
    {
        red = ppm.pixels[i].r * 0.393 + ppm.pixels[i].g * 0.769 + ppm.pixels[i].b * 0.189;
        green = ppm.pixels[i].r * 0.349 + ppm.pixels[i].g * 0.686 + ppm.pixels[i].b * 0.168;
        blue = ppm.pixels[i].r * 0.272 + ppm.pixels[i].g * 0.534 + ppm.pixels[i].b * 0.131;
        
        if (red > 255) red = 255;
        if (green > 255) green = 255;
        if (blue > 255) blue = 255;
        
        ppm.pixels[i].r = red;
        ppm.pixels[i].g = green;
        ppm.pixels[i].b = blue;
    } // for
} // Sepia

// read the input information
void readPixel();
void readPixel() {
    
    string eline;
    
    int t;
    
    // column (replace width)
    int column = 0;
    
    // row (replace height)
    int row = 0;
    
    // determine the line containing width and height or not
    int whline = 0;
    
    // original size is 5
    if (indexc == 0) {
        indexc = 5;
        readin.pixels = new Pixel[indexc];
    }
    
    // start reading the input
    while (getline(cin, eline)) {
        stringstream convert(eline);
        // read the first line
        if (m3 == 0) {
            
            while (convert>>t) {

                if (m3%3==0) {
                    if (t>255) {
                        valid = 1;
                        break;
                    } else {
                        readin.pixels[indexs].r = t;
                        ++m3;
                    } // exit
                }
                
                else if (m3%3==1) {
                    if (t>255) {
                        valid = 1;
                        break;
                    } else {
                        readin.pixels[indexs].g = t;
                        ++m3;
                    } // exit
                }
                
                else {
                    if (t>255) {
                        valid = 1;
                        break;
                    } else {
                        readin.pixels[indexs].b = t;
                        ++m3;
                    } // exit
                } // exit
                
                // calculate the current size of pixel
                indexs = m3/3;
                
                // resize if current size is equal to current capacity
                if (indexs >= indexc) {
                    Pixel *repixel = new Pixel[indexc*2];
                    for (int i = 0;i <= indexs;++i) {
                        repixel[i] = readin.pixels[i];
                    }
                    delete [] readin.pixels;
                    readin.pixels = repixel;
                    indexc *= 2;
                } // exit
            } // while
            
            /* the invalid situation that
             * the first line only has no
             * number or 1 number or 2 number */
            if (m3==2 || m3==0 || m3==1) {
                valid = 1;
                break;
            } // exit
            
            // determine valid or not
            if (valid == 1) {
                break;
            } //exit
            
            // the valid situation and go on
            if (m3%3 == 0) {
                column = m3/3;
                ++row;
                valid = 0;
            }
            
            else {
                valid = 1;
                break;
            } // exit
        }
        
        // read the rest lines of input
        else {
            while (convert>>t) {
                
                if (m3%3==0) {
                    if (t>255) {
                        valid = 1;
                        break;
                    } else {
                        readin.pixels[indexs].r = t;
                        ++m3;
                    } // exit
                }
                
                else if (m3%3==1) {
                    if (t>255) {
                        valid = 1;
                        break;
                    } else {
                        readin.pixels[indexs].g = t;
                        ++m3;
                    } // exit
                }
                
                else {
                    if (t>255) {
                        valid = 1;
                        break;
                    } else {
                        readin.pixels[indexs].b = t;
                        ++m3;
                    } // exit
                } // exit
                
                // calculate the current size of pixel
                indexs = m3/3;
                
                // increment for it each number of the current line
                ++whline;
                
                // resize if current size is equal to current capacity
                if (indexs >= indexc) {
                    Pixel *repixel = new Pixel[indexc*2];
                    for (int i = 0;i <= indexs;++i) {
                        repixel[i] = readin.pixels[i];
                    }
                    delete [] readin.pixels;
                    readin.pixels = repixel;
                    indexc *= 2;
                } // exit
            } // while
            
            // increment for the number of lines
            ++row;
            
            // not assign width of ppmarray yet
            if (indexw == 0) {
                
                // determine the last second line or not
                if (whline==2) {
                    if (readin.pixels[indexs].r != column || readin.pixels[indexs].g != (row-1)) {
                        valid = 1;
                        break;
                    } else {
                        // assign the height and width of ppmarray
                        indexw = readin.pixels[indexs].r;
                        indexh = readin.pixels[indexs].g;
                    } // exit
                } // exit
                
                // determine there is a non-num
                if (whline==0 || whline ==1) {
                    valid = 1;
                    break;
                }// exit
                
                // determine valid or not
                if (valid == 1) {
                    break;
                } // exit
                
                // other invalid situation
                if (whline !=2 && whline !=1 && whline !=0 && whline%3 != 0) {
                    valid = 1;
                    break;
                } // exit
                
                // zero the whline
                whline = 0;
                
            }
            
            /* the input of number is over,
             * then start reading order */
            else {
                
                // flip order
                if (eline=="flip") {
                    flipHorizontal(readin);
                }
                // ratate order
                else if (eline=="rotate") {
                    rotate(readin);
                }
                // sepia order
                else if (eline=="sepia") {
                    sepia(readin);
                }
                // wrong order
                else {
                    valid = 1;
                    break;
                } // exit
            } // exit
        } // while
    } // while (the getline one)
} //ReadPixel



void print();
void print() {
    
    // invalid: standard error output
    if (valid == 1) {
        cerr << "cnmcs246" << endl;
    }
    // valid ouput
    else if (valid == 0) {
        cout << "P3" << endl;
        cout << indexw << " ";
        cout << indexh << endl;
        cout << "255" << endl;
        int crow = 1;
        for (int i = 0;i<indexs*3;++i) {
            if ((i+1)%3==0 && (i+1)/3==indexw*crow) {
                cout << readin.pixels[i/3].b << endl;
                ++crow;
            }
            
            else {
                if (i%3==0) {
                    cout << readin.pixels[i/3].r << " ";
                } else if (i%3 == 1) {
                    cout << readin.pixels[i/3].g << " ";
                } else {
                    cout << readin.pixels[i/3].b << " ";
                }
            }
        }
    }
    // invalid: standard error input
    else {
        cerr << "cnmcs246" << endl;
    } 
} // Print



int main() {
    readPixel();
    cin.clear();
    print();
    delete [] readin.pixels;
}
