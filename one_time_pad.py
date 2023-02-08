import sys
import argparse
import string
import random
import itertools
from string import printable # A list of printable characters to validate against
from typing import List

def encrypt(file_content, otp):
    #Initialize cipher text
    ciphertext = ""
    #Iterate through the file_content and XOR with otp
    for char, pad in zip(file_content, otp):
        #Xor char and pad with ord
        xored_char = ord(char) ^ ord(pad)
        #Save resulting character in ciphertext string
        ciphertext += (chr(xored_char))
    #Return result
    return ciphertext

def decrypt(file_content,otp):
    #Initialize plain text
    plaintext = ""

    for char, pad in zip(file_content, otp):
         #Xor char and pad with ord
        xored_char = ord(char) ^ ord(pad)
         #Save resulting character in ciphertext string
        #temp=chr(xored_char)
        plaintext += chr(xored_char)
    #Return result    
    return plaintext

def xor_ciphertexts(ciphertexts):
    temp=[]
    for j in range(len(ciphertexts)):
        print(j,ciphertexts[j])
        for i in range(len(ciphertexts)):
            if not j==i:           
                temp.append(encrypt(ciphertexts[j],ciphertexts[i]))
    print(temp)

def main(arguments):

    parser = argparse.ArgumentParser(formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("-e", "--encrypt", help="Encrypt text file", type=argparse.FileType('r'))
    parser.add_argument("-d", "--decrypt", help="Decrypt ciphertext file", type=argparse.FileType('r'))
    parser.add_argument("-p", "--otp", help="One-time pad used for encryption/decryption", type=argparse.FileType('r'))

    args = parser.parse_args(arguments)
    
    
    if args.encrypt:
        file_content = args.encrypt.read()
        if args.otp:
            otp = args.otp.read()
        else:
            #Set characters var as all printable chracters then randomize
            characters = string.printable
            otp = ''.join(random.choice(characters) for i in range(len(file_content)))
        #Call encryption function
        encrypted_text=encrypt(file_content,otp)
        print(encrypted_text)    
    if args.decrypt:
        if args.otp:
            otp = args.otp.read()
            file_content = args.decrypt.read()
            #Call decryption function
            decrypted_text=decrypt(file_content,otp)
            print(decrypted_text)
        else:
            parser.error("-d/--decrypt requires -p/--otp")

if __name__ == '__main__':
    main(sys.argv[1:])