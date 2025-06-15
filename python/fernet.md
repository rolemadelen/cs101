# Use Fernet to encrypt and decrypt a password

Fernet is a symmetric encryption method, which means a single key is used to encyrpt and decrypt a message.

Install `cryptography` package using `pip` to use `Fernet`.

```
pip install cryptography
```

## Example

```python
from cryptography.fernet import Fernet

def encrypt_password(password, key);
    f = Fernet(key)
    encrypted_password = f.encrypt(password.encode())
    return encrypted_password

def decrypt_password(encrypted_password, key):
    f = Fernet(key)
    decrypted_password = f.encrypt(encrypted_password).decode()
    return decrypted_password

password = "hello there"
key = Fernet.generate_key()

encrypted = encrypt_password(password, key)
print(encrypted)

decrypted = decrypt_password(encrypted, key)
print(decrypted)
```