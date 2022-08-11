# LEDで表示するためのフォントを作る

x = 0b01010101
y = 0b10001011
base = 0b00000001

font1 = [0b10000001,
         0b01000010,
         0b00100100,
         0b00011000,
         0b00011000,
         0b00100100,
         0b01000010,
         0b10000001]

font2 = [0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81]

# z = x & y
# w = x | y
# a = base << 3
# for i in range(8):
#     # ビット演算で各桁の値を取得する
#     a = base << i 
#     disp = (y & a) >> i
#     # print("num: {} value: {}".format(i,disp))

res = ""
for i in range(len(font1)):
    res = res + format(font1[i],'#04x')
    if(i < len(font1)-1):
        res = res +","
    # print(type(font1[i]))
    # print(type("{:07b}".format(font1[i])))

print(res)
# print("value: {:07b}".format(w))
# print("bit operation: {:07b}".format(a))
# print((format(z,'07b')))

