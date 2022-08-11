# LEDで表示するためのフォントを作る

x = 0b01010101
y = 0b10001011
base = 0b00000001

# font2 = [0b00000000,
#          0b00000000,
#          0b00000000,
#          0b00000000,
#          0b00000000,
#          0b00000000,
#          0b00000000,
#          0b00000000]

font1 = [0b10000001,
         0b01000010,
         0b00100100,
         0b00011000,
         0b00011000,
         0b00100100,
         0b01000010,
         0b10000001]

font2 = [0b00000000,
         0b00000010,
         0b00000100,
         0b00001000,
         0b01111000,
         0b00001000,
         0b00001000,
         0b00001000]

# z = x & y
# w = x | y
# a = base << 3
# for i in range(8):
#     # ビット演算で各桁の値を取得する
#     a = base << i 
#     disp = (y & a) >> i
#     # print("num: {} value: {}".format(i,disp))

# print("value: {:07b}".format(w))
# print("bit operation: {:07b}".format(a))
# print((format(z,'07b')))

def encodeFont(font):
    res = ""
    for i in range(len(font)):
        res = res + format(font[i],'#04x')
        if(i < len(font)-1):
            res = res +","
        # print(type(font1[i]))
        # print(type("{:07b}".format(font1[i])))

    print(res)

encodeFont(font2)

# 作ったフォント

# ア 0x00,0x7e,0x02,0x14,0x18,0x10,0x10,0x20
# イ 0x00,0x02,0x04,0x08,0x78,0x08,0x08,0x08



