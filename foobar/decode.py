import base64

def decode(msg, key):
    result = []
    for i, c in enumerate(base64.b64decode(msg)):
        result.append(chr(c ^ ord(key[i % len(key)])))
    return ''.join(result)
