BLTG Core version *2.0.1.0* is now available from:  <https://github.com/Block-Logic-Technology-Group/bltg/releases>

This is a new minor version release, including various fixes and performance and UI improvements.

Please report bugs using the issue tracker at github: <https://github.com/Block-Logic-Technology-Group/bltg/issues>


Supplemental Update
==============

BLTG Core v2.0.1.0 is a **supplemental update** to v2.0.0 containing minor bug fixes. Users are still advised to read the [v3.2.0 Release Notes](https://github.com/Block-Logic-Technology-Group/bltg/blob/master/doc/release-notes/release-notes-3.2.0.md) to familiarize themselves with the major feature changes.

While updating from v2.0.0 is not required, it is highly recommended, especially for anyone encountering the issues detailed in the Notable Changes section below.

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely shut down (which might take a few minutes for older versions), then run the installer (on Windows) or just copy over /Applications/BLTG-Qt (on Mac) or bltgd/bltg-qt (on Linux).


Compatibility
==============

BLTG Core is extensively tested on multiple operating systems using the Linux kernel, macOS 10.10+, and Windows 7 and later.

Microsoft ended support for Windows XP on [April 8th, 2014](https://www.microsoft.com/en-us/WindowsForBusiness/end-of-xp-support), No attempt is made to prevent installing or running the software on Windows XP, you can still do so at your own risk but be aware that there are known instabilities and issues. Please do not report issues about Windows XP to the issue tracker.

Apple released it's last Mountain Lion update August 13, 2015, and officially ended support on [December 14, 2015](http://news.fnal.gov/2015/10/mac-os-x-mountain-lion-10-8-end-of-life-december-14/). BLTG Core software starting with v2.1.0 will no longer run on MacOS versions prior to Yosemite (10.10). Please do not report issues about MacOS versions prior to Yosemite to the issue tracker.

BLTG Core should also work on most other Unix-like systems but is not frequently tested on them.


Notable Changes
==============

Minimum Supported MacOS Version
------

The minimum supported version of MacOS (OSX) has been moved from 10.8 Mountain Lion to 10.10 Yosemite. Users still running a MacOS version prior to Yosemite will need to upgrade their OS if they wish to continue using the latest version(s) of the PIVX Core wallet.

Bug Fixes
------

### zBLTG status:

zBLTG will be disabled for the forseable future as more testing is required.


Performance Improvements
------

### New checkpoints

More recent checkpoints have been added for mainnet. These help alleviate some of the load when (re-)syncing from the network.

## Credits

Thanks to everyone who directly contributed to this release:

 - cpass78
 - minerric

 and of course
 - PIVX team for an awsome codebase