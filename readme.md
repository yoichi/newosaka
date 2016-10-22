Translater from Japanese to Osaka dialect.

This module is a transportation of newosaka program written in C.

# Usage

## from command line

```
% echo "ありがとう" | python3 osaka.py
おおきに
```

## from python

```
% python3
Python 3.5.1 (default, Mar 30 2016, 03:47:25)
[GCC 4.2.1 Compatible Apple LLVM 7.3.0 (clang-703.0.29)] on darwin
Type "help", "copyright", "credits" or "license" for more information.
>>> import osaka
>>> osaka.translate("ありがとう")
'おおきに'
```

# License

Follow the original license in newosaka/ReadMe.euc.
