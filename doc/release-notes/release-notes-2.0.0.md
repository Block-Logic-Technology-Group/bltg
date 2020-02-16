BLTG Core version *2.0.0* is now available from:  <https://github.com/Block-Logic-Technology-Group/bltg/releases>

This is a new minor version release, including various bug fixes and performance improvements, as well as updated translations.

Please report bugs using the issue tracker at github: <https://github.com/Block-Logic-Technology-Group/bltg/issues>

Non-Mandatory Update
==============

BLTG Core v2.0.0 is a mandatory update to move our whole network onto a new codebase starting a brand new Network.

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely shut down (which might take a few minutes for older versions), then run the installer (on Windows) or just copy over /Applications/BLTG-Qt (on Mac) or bltgd/bltg-qt (on Linux).


Compatibility
==============

BLTG Core is extensively tested on multiple operating systems using
the Linux kernel, macOS 10.8+, and Windows Vista and later.

Microsoft ended support for Windows XP on [April 8th, 2014](https://www.microsoft.com/en-us/WindowsForBusiness/end-of-xp-support),
No attempt is made to prevent installing or running the software on Windows XP, you
can still do so at your own risk but be aware that there are known instabilities and issues.
Please do not report issues about Windows XP to the issue tracker.

BLTG Core should also work on most other Unix-like systems but is not
frequently tested on them.

###  MacOS 10.13 High Sierra

**Currently there are issues with the gitian release on MacOS version 10.13 (High Sierra), no reports of issues on older versions of MacOS.**

Notable Changes
==============

zBLTG Updates
--------------

### zBLTG status:

zBLTG will be disabled for the forseable future as more testing is required.


### Switch to libsecp256k1 signature verification

Here is the long overdue update for BLTG to let go of OpenSSL in its consensus code. The rationale behind it is to avoid depending on an external and changing library where our consensus code is affected. This is security and consensus critical. BLTG users will experience quicker block validations and sync times as block transactions are verified under libsecp256k1.

The recent [CVE-2018-0495](https://www.nccgroup.trust/us/our-research/technical-advisory-return-of-the-hidden-number-problem/) brings into question a potential vulnerability with OpenSSL (and other crypto libraries) that libsecp256k1 is not susceptible to.



*2.0.0* Change log
--------------

Detailed release notes follow. This overview includes changes that affect behavior, code moves, refactoring and string updates. For convenience in locating the code changes and accompanying discussion, both the pull request and git merge commit are mentioned.


## Credits
Thanks to everyone who directly contributed to this release:

 - Cpass78
 - minerric

 and of course
 - PIVX team for an awsome codebase
