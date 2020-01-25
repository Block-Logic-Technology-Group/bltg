BLTG Core version *3.0.1* is now available from:  <https://github.com/Block-Logic-Technology-Group/bltg/releases>

This is a new minor version release, including various bug fixes and performance improvements.

Please report bugs using the issue tracker at github: <https://github.com/Block-Logic-Technology-Group/bltg/issues>

As Block-Logic is based on open-source code from the pivx project, an exhaustive description of all changes can be found at <https://github.com/PIVX-Project/PIVX/releases>


Supplemental Update
==============

BLTG Core v3.0.1 is a supplemental update for all users.

Masternodes will need to be restarted once both the masternode daemon and the controller wallet have been upgraded.

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely shut down (which might take a few minutes 
for older versions), then run the installer (on Windows) or just copy over /Applications/BLTG-Qt (on Mac) or bltgd/bltg-qt (on Linux).

Compatibility
==============

BLTG Core is extensively tested on multiple operating systems using the Linux kernel, macOS 10.10+, and Windows 7 and later.

Microsoft ended support for Windows XP on [April 8th, 2014](https://www.microsoft.com/en-us/WindowsForBusiness/end-of-xp-support), 
No attempt is made to prevent installing or running the software on Windows XP, you can still do so at your own risk 
but be aware that there are known instabilities and issues. Please do not report issues about Windows XP to the issue tracker.

Apple released it's last Mountain Lion update August 13, 2015, and officially ended support 
on [December 14, 2015](http://news.fnal.gov/2015/10/mac-os-x-mountain-lion-10-8-end-of-life-december-14/). 
BLTG Core software starting with v3.0.0 will no longer run on MacOS versions prior to Yosemite (10.10). 
Please do not report issues about MacOS versions prior to Yosemite to the issue tracker.

BLTG Core should also work on most other Unix-like systems but is not frequently tested on them.


Notable Changes
==============

### Additional checkpoints to aid in forking scenarios

*3.0.1* Change log
==============

Detailed release notes follow. This overview includes changes that affect behavior, not code moves, refactors and string updates.

### P2P Protocol and Network Code

 -

## Credits

Thanks to everyone who directly contributed to this release:

 - cpass78

 and of course
 - PIVX team for an awesome codebase