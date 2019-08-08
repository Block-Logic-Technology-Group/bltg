BLTG Core version *3.0.0* is now available from:  <https://github.com/Block-Logic-Technology-Group/bltg/releases>

This is a new major version release, including various bug fixes and performance improvements, as well as updated translations.

Please report bugs using the issue tracker at github: <https://github.com/Block-Logic-Technology-Group/bltg/issues>


Mandatory Update
==============

BLTG Core v3.0.0 is a mandatory update for all users. This release contains

Masternodes will need to be restarted once both the masternode daemon and the controller wallet have been upgraded.

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely shut down (which might take a few minutes for older versions), then run the installer (on Windows) or just copy over /Applications/BLTG-Qt (on Mac) or bltgd/bltg-qt (on Linux).

Compatibility
==============

BLTG Core is extensively tested on multiple operating systems using the Linux kernel, macOS 10.10+, and Windows 7 and later.

Microsoft ended support for Windows XP on [April 8th, 2014](https://www.microsoft.com/en-us/WindowsForBusiness/end-of-xp-support), No attempt is made to prevent installing or running the software on Windows XP, you can still do so at your own risk but be aware that there are known instabilities and issues. Please do not report issues about Windows XP to the issue tracker.

Apple released it's last Mountain Lion update August 13, 2015, and officially ended support on [December 14, 2015](http://news.fnal.gov/2015/10/mac-os-x-mountain-lion-10-8-end-of-life-december-14/). BLTG Core software starting with v3.0.0 will no longer run on MacOS versions prior to Yosemite (10.10). Please do not report issues about MacOS versions prior to Yosemite to the issue tracker.

BLTG Core should also work on most other Unix-like systems but is not frequently tested on them.


Notable Changes
==============

## Zerocoin removal

Recent exploits of the Zerocoin protocol (Wrapped serials and broken P1 proof) required us to enable the zerocoin spork and deactivate zBLTG functionality.

Given that BLTG is a non-currency and is meant as a token to provide other services, as well as the issues presented in the Zerocoin protocol, the Zerocoin functionality has been completely disabled starting with this release.

Complete removal will continue to occur over future updates. This won't negatively impact wallet performance or functionality.

## GUI Changes

### Options Dialog Cleanup

The options/settings UI dialog has been cleaned up to no longer show settings that are wallet related when running in "disable wallet" (`-disablewallet`) mode.

## RPC Changes

### Removal of Deprecated Commands

The `masternode` and `mnbudget` RPC commands, which were marked as deprecated in PIVX Core v2.3.1 (September 19, 2017), have now been completely removed from BLTG Core.

Several new commands were added in v2.3.1 to replace the two aforementioned commands, reference the [v2.3.1 Release Notes](https://github.com/PIVX-Project/PIVX/blob/master/doc/release-notes/release-notes-2.3.1.md#rpc-changes) for further details.

### New `getblockindexstats` Command

A new RPC command (`getblockindexstats`) has been introduced which serves the purpose of obtaining statistical information on a range of blocks. The information returned is as follows:
  * transaction count (not including coinbase/coinstake txes)
  * transaction count (including coinbase/coinstake txes)
  * total transaction bytes
  * total fees in block range
  * average fee per kB

Command Reference:
```$xslt
getblockindexstats height range ( fFeeOnly )
nReturns aggregated BlockIndex data for blocks
height, height+1, height+2, ..., height+range-1]

nArguments:
1. height             (numeric, required) block height where the search starts.
2. range              (numeric, required) number of blocks to include.
3. fFeeOnly           (boolean, optional, default=False) return only fee info.
```
Result:
```
{
  first_block: x,              (integer) First counted block
  last_block: x,               (integer) Last counted block
  txcount: xxxxx,              (numeric) tx count (excluding coinbase/coinstake)
  txcount_all: xxxxx,          (numeric) tx count (including coinbase/coinstake)
  txbytes: xxxxx,              (numeric) Sum of the size of all txes over block range
  ttlfee: xxxxx,               (numeric) Sum of the fee amount of all txes over block range
  ttlfee_all: xxxxx,           (numeric) Sum of the fee amount of all txes over block range
  feeperkb: xxxxx,             (numeric) Average fee per kb
}
```

## Build System Changes

### New Architectures for Depends

The depends system has new added support for the `s390x` and `ppc64el` architectures. This is done in order to support the future integration with [Snapcraft](https://www.snapcraft.io), as well as to support any developers who may use systems based on such architectures.

### Basic CMake Support

While the existing Autotools based build system is our standard build system, and will continue to be so, we have added basic support for compiling with CMake on macOS and linux systems.

This is intended to be used in conjunction with IDEs like CLion (which relies heavily on CMake) in order to streamline the development process. Developers can now use, for example, CLion's internal debugger and profiling tools.

Note that it is still required to have relevant dependencies installed on the system for this to function properly.

*3.0.0* Change log
==============

Detailed release notes follow. This overview includes changes that affect behavior, not code moves, refactors and string updates. For convenience in locating the code changes and accompanying discussion, both the pull request and git merge commit are mentioned.

With the exception of Zerocoin related items, this release integrates all the below changes from PIVX project

### Core
 - #875 `a99c2dd3bb` [Zerocoin] GMP BigNum: Fix limits for random number generators (random-zebra)
 - #888 `0c071c3fd0` [Zerocoin] remove CTransaction::IsZerocoinSpend/IsZerocoinMint (random-zebra)
 - #891 `855408c2c3` [ZPIV] Zerocoin public coin spend. (furszy)
 - #897 `65bd788945` [zPIV] Disable zerocoin minting (random-zebra)
 - #899 `4b22a09024` [zPIV] Disable zPIV staking (random-zebra)
 - #909 `458b08c8f2` [Consensus] Mainnet public spend enforcement height set. (furszy)
 - #924 `988b33dab8` [Backport] Max tip age to consider a node in IBD status customizable. (furszy)
 - #925 `a9827a0e63` [Consensus] Time checks (warrows)

### Build System
 - #810 `a373fee908` [Depends] Fix archs (fixes s390x and ppc64el builds on snap) (cevap)
 - #906 `8a47747b59` [Build] Add CMake Support (Fuzzbawls)
 - #910 `07c8fb8f88` [Build] Clean all coverage files during make clean (Fuzzbawls)
 - #913 `473976c619` [Depends] Update from upstream (Fuzzbawls)
 - #914 `5a43ea790a` [Gitian] Bump gitian build versions (Fuzzbawls)
 - #917 `b38ef04838` [Build] TravisCI Update (Fuzzbawls)
 - #922 `0f98fd4d3f` [Build] Fix app name casing in mac deploy related files (Fuzzbawls)

### P2P Protocol and Network Code
 - #908 `95b584effd` [NET] Non-running dns servers removed from chainParams. (furszy)
 - #929 `7e8855d910` [Net] Update hard-coded seeds (Fuzzbawls)
 - #930 `5061b486c2` [Net] Add a couple new testnet checkpoints (Fuzzbawls)

### GUI
 - #874 `23f17ce021` [Qt] Add new budget colors (warrows)
 - #895 `0417d52ef9` [QT] Options UI cleanup (Alko89)
 - #896 `b2fcefee93` [UI] Simplify Qt margins. (warrows)
 - #898 `3d496cc746` [Qt] Fixup duplicate label names (Fuzzbawls)
 - #900 `5f7559bc7b` [UI] Fix improperly parented walletView and segmentation fault on QT 5.10 (Julian Meyer)
 - #928 `2482572f89` [Qt] Update Translations (Fuzzbawls)

### RPC/REST
 - #877 `54c8832d80` [RPC] Remove deprecated masternode/budget RPC commands (Fuzzbawls)
 - #901 `be3aab4a00` [RPC] Fix typos and oversights in listunspent (CaveSpectre11)
 - #911 `484c070b22` [RPC] add 'getblockindexstats' function (random-zebra)

### Wallet
 - #813 `80bf51e7c9` [Refactoring] [Move Only] Move wallet files into their own folder (warrows)
 - #916 `a4f02ed946` [Staking] Don't assert if we were beaten to the block (CaveSpectre11)

### Unit Tests
 - #806 `fc6b5a191d` [Test] Create new per-test fixtures (Wladimir J. van der Laan)
 - #902 `8adeeb9727` [Tests] Add tests for CAddrMan (warrows)

### Miscellaneous
 - #744 `7e52f58b82` [Refactor] Refactor bignum header file into several files (warrows)
 - #808 `8b54f7150b` [Scripts] Add optimize pngs python script (cevap)
 - #824 `3323f26848` [Refactor] Remove stale obfuscation code (Fuzzbawls)
 - #830 `81038da4f8` [Refactor] Remove BOOST_FOREACH (Fuzzbawls)
 - #844 `0a0dcf0d4e` [Refactor] Replace deprecated auto_ptr with unique_ptr (cevap)
 - #856 `da26ddeeb9` [Refactor] Move per-chain budget cycle blocks to chainparams (Fuzzbawls)
 - #879 `5f0d72659c` [Refactor] Rename ui_interface.h file (Fuzzbawls)
 - #890 `fddac44eab` [Refactor] Remove unused setStakeSeen variable (warrows)
 - #903 `68c81c407a` [Log] Handle errors during log message formatting (warrows)
 - #904 `6f597629d8` [zPIV] Free memory from ToString() (warrows)
 - #912 `5f167c2c7e` [Cleanup] compiler warnings in coinSpend object. (furszy)
 - #919 `c0233e4af6` [zPIV] Debug missing jump line. (Matias Furszyfer)
 - #920 `a56cc2948d` [Docs] Overhaul documentation files (Fuzzbawls)
 - #921 `893183339e` [Scripts] Overhaul supplemental python/shell scripts (Fuzzbawls)
 - #926 `49a69b8931` [Doc] 3.3.0 Notable Changes (Fuzzbawls)
 - #927 `048d1295dc` [Trivial] Update header copyright years (Fuzzbawls)

## Credits

Thanks to everyone who directly contributed to this release:

 - cpass
 - minerric

 and of course
 - PIVX team for an awesome codebase