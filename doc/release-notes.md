BLTG Core version *3.0.0* is now available from:  <https://github.com/Block-Logic-Technology-Group/bltg/releases>

This is a new major version release, including various bug fixes and performance improvements, as well as updated translations.

Please report bugs using the issue tracker at github: <https://github.com/Block-Logic-Technology-Group/bltg/issues>

As Block-Logic is based on open-source code from the pivx project, an exhaustive description of all changes can be found at <https://github.com/PIVX-Project/PIVX/releases>


Mandatory Update
==============

BLTG Core v3.0.0 is a mandatory update for all users.

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

Detailed release notes follow. This overview includes changes that affect behavior, not code moves, refactors and string updates.

With the exception of Zerocoin related items, this release integrates all the below changes from PIVX project

### Core
 - #875 a99c2dd3bb [Zerocoin] GMP BigNum: Fix limits for random number generators (random-zebra)
 - #888 0c071c3fd0 [Zerocoin] remove CTransaction::IsZerocoinSpend/IsZerocoinMint (random-zebra)
 - #891 855408c2c3 [ZPIV] Zerocoin public coin spend. (furszy)
 - #897 65bd788945 [zPIV] Disable zerocoin minting (random-zebra)
 - #899 4b22a09024 [zPIV] Disable zPIV staking (random-zebra)
 - #909 458b08c8f2 [Consensus] Mainnet public spend enforcement height set. (furszy)
 - #924 988b33dab8 [Backport] Max tip age to consider a node in IBD status customizable. (furszy)
 - #925 a9827a0e63 [Consensus] Time checks (warrows)

 - #549 8bf13a5ad [Crypto] Switch to libsecp256k1 signature verification and update the lib (warrows)
 - #609 6b73598b9 [MoveOnly] Remove zPIV code from main.cpp (presstab)
 - #610 6c3bc8c76 [Main] Check whether tx is in chain in ContextualCheckZerocoinMint(). (presstab)
 - #624 1a82aec96 [Core] Missing seesaw value for block 325000 (warrows)
 - #636 d359c6136 [Main] Write to the zerocoinDB in batches (Fuzzbawls)

### Build System
 - #810 a373fee908 [Depends] Fix archs (fixes s390x and ppc64el builds on snap) (cevap)
 - #906 8a47747b59 [Build] Add CMake Support (Fuzzbawls)
 - #910 07c8fb8f88 [Build] Clean all coverage files during make clean (Fuzzbawls)
 - #913 473976c619 [Depends] Update from upstream (Fuzzbawls)
 - #914 5a43ea790a [Gitian] Bump gitian build versions (Fuzzbawls)
 - #917 b38ef04838 [Build] TravisCI Update (Fuzzbawls)
 - #922 0f98fd4d3f [Build] Fix app name casing in mac deploy related files (Fuzzbawls)
 - #858 a2c801205e [Build] [macOS] Fix macOS dmg issue (10.12+) (Jonas Schnelli)
 - #866 9cd6016f3a [Build] Update debian contrib files (Fuzzbawls)
 - #758 81c7c4764c [Depends] Update libsecp256k1 to latest master (warrows)
 - #804 4a8e46a158 [Depends] Update zmq to 4.3.1 (Dimitris Apostolou)
 - #795 1920f3e8ad [Build] Add support for RISC-V and build it with gitian (cevap)
 - #786 44226f225e [Build] add gitian build python script (cevap)
 - #783 ccba68e425 [Depends] Update QT to 5.9.7 (cevap)
 - #754 b9cbeb0951 [Build] Update Build/Depends systems from upstream (Fuzzbawls)
 - #752 63fb77b0a9 [Build] Fix Thread Safety Analysis Warnings (Fuzzbawls)
 - #749 36ff23553c [Build] Update genbuild.sh script (Fuzzbawls)
 - #681 95ec0763cf [Depends] Add gmp bignum support for zerocoin lib (warrows)
 - #704 f0a427bfd7 [Build] GCC-7 and glibc-2.27 back compat (Fuzzbawls)
 - #706 d3c5b808dd [Build] Remove throw keywords in leveldb function signatures (Fuzzbawls)
 - #708 72cd07186b [Build] Remove stale m4 file (Fuzzbawls)
 - #671 b003052103 [Build] Update to latest leveldb (Fuzzbawls)
 - #605 b4d82c944 [Build] Remove unnecessary BOOST dependency (Mrs-X)
 - #622 b8c672c98 [Build] Make sure Boost headers are included for libzerocoin (Fuzzbawls)
 - #639 98c7a4f65 [Travis] Add separate job to check doc/logprint/subtree (Fuzzbawls)
 - #648 9950fce59 [Depends] Update Qt download url (fanquake)

### P2P Protocol and Network Code
 - #908 95b584effd [NET] Non-running dns servers removed from chainParams. (furszy)
 - #929 7e8855d910 [Net] Update hard-coded seeds (Fuzzbawls)
 - #930 5061b486c2 [Net] Add a couple new testnet checkpoints (Fuzzbawls)
 - #880 a890dc97cd [NET] Valid forked blocks rejected fix. (furszy)
 - #884 013676df00 [Net] Add additional checkpoints (Fuzzbawls)
 - #887 ec7993eac8 [Net] Fix incorrect last checkpoint timestamp (Fuzzbawls)
 - #861 909ed11702 [Net] Add new checkpoints for mainnet/testnet (Fuzzbawls)
 - #843 817cec4ff4 [Net] Increment Protocol Version (Fuzzbawls)
 - #837 d241b5ed77 [Zerocoin][UNIT TEST][RPC] Wrapped serials. (random-zebra)
 - #803 065f94118d [NET] Invalid blocks from forks stored on disk fix + blocks DoS spam filter. (furszy)
 - #802 ed0dd2a20a [Refactor] Remove begin/end_ptr functions (warrows)
 - #768 204c038a4d [Net] Zerocoin Light Node Protocol (furszy)
 - #798 a663bccea7 [Net] Improve addrman Select() performance when buckets are nearly empty (Pieter Wuille)
 - #800 7fa20d69f6 [Net] nLastTry is only used for addrman entries (Pieter Wuille)
 - #740 5f7cb412a3 [Net] Pull uacomment in from upstream (Fuzzbawls)
 - #774 167c7fa6d0 [Budget] Make checks for MN-autovoting deterministic (Mrs-X)
 - #770 ab9cf3629c [Main] Do not record zerocoin tx's in ConnectBlock() if it is fJustCheck (presstab)
 - #705 6a5b64bc21 [Main] Check Lock Time Verify (presstab)
 - #608 a602d00eb [Budget] Make sorting of finalized budgets deterministic (Mrs-X)
 - #647 3aa3e5c97 [Net] Update hard-coded fallback seeds (Fuzzbawls)

### GUI
 - #874 23f17ce021 [Qt] Add new budget colors (warrows)
 - #895 0417d52ef9 [QT] Options UI cleanup (Alko89)
 - #896 b2fcefee93 [UI] Simplify Qt margins. (warrows)
 - #898 3d496cc746 [Qt] Fixup duplicate label names (Fuzzbawls)
 - #900 5f7559bc7b [UI] Fix improperly parented walletView and segmentation fault on QT 5.10 (Julian Meyer)
 - #928 2482572f89 [Qt] Update Translations (Fuzzbawls)
 - #860 2cefebd1f7 [Qt] Prevent double deletion of progress dialog (Fuzzbawls)
 - #852 37e88b892f [QT] Fix a display bug about zPIV mints (warrows)
 - #863 89b84a4f5a [Qt] Stop using a solid white image as a border image (Fuzzbawls)
 - #850 e488db7334 [Qt] Update localizations from Transifex (Fuzzbawls)
 - #847 fc924c1f63 [Qt] Fix to display missing clock5.png tx image (joeuhren)
 - #840 757d81c4a9 [QT] cleanup, remove old trading dialog form (furszy)
 - #826 0d738b3dc0 [Qt] Fix a windows only crash when r-clicking a proposal (warrows)
 - #792 c12697469b [UI] Add a budget monitoring and voting tab (warrows)
 - #794 8dcb52fcd4 [UI] Open related options tab when clicking automint icon (warrows)
 - #791 c0aa454e19 [Qt] Fix Missing Explorer Icon (sicXnull)
 - #779 d617c85a89 [Qt] Periodic translation update (Fuzzbawls)
 - #781 10e1a8a306 [Qt] Don't show staking/automint status icons without a wallet (Fuzzbawls)
 - #776 3fcdc932d9 [Qt] Add a security warning to the debug console's default output. (Fuzzbawls)
 - #747 feb87c10fa [GUI] Hide orphans - contextMenu action (random-zebra)
 - #741 ea2637838c [GUI] Sort by 'data' in zPIV and coin control dialogs (random-zebra)
 - #733 9a792d73e9 [GUI] Hide orphans (random-zebra)
 - #735 44840c5069 [Qt] Stop using dummy strings in clientversion.cpp (Fuzzbawls)
 - #725 793db15baf [UI] Sort numbers correctly in zPIV and coin control dialogs (random-zebra)
 - #714 bf2ad88066 [UI] Add address field in receive tab (warrows)
 - #683 ec1180b52c [Qt] receivecoinsdialog - address control + clean UI (random-zebra)
 - #677 29fab5982f [Qt] change colors for tx labels in history/overview (random-zebra)
 - #693 022b58257c [UI] Add address to the payment request history (warrows)
 - #698 3f35bc81d8 [Qt] Remove Qt4 build support & code fallbacks (Wladimir J. van der Laan)
 - #655 de0c4e0888 [Qt] Fix PIV balances on overview page (Fuzzbawls)
 - #680 71ac5285e5 [Qt] Privacy dialog: hide/show denominations (random-zebra)
 - #675 8a26ba0b07 [Qt] SwiftX - intuitiveness (random-zebra)
 - #668 4a68c9ed43 [Qt] Clean up Multisend Dialog UI (Fuzzbawls)
 - #580 c296b7572 Fixed Multisend dialog to show settings properly (SHTDJ)
 - #598 f0d894253 [GUI] Fix wrongly displayed balance on Overview tab (Mrs-X)
 - #600 217433561 [GUI] Only enable/disable PrivacyDialog zPIV elements if needed. (presstab)
 - #612 6dd752cb5 [Qt] Show progress percent for zpiv reindex operations (Fuzzbawls)
 - #626 9b6a42ba0 [Qt] Add Tor service icon to status bar (Fuzzbawls)
 - #629 14e125795 [Qt] Remove useless help button from QT dialogs (windows) (warrows)
 - #646 c66b7b632 [Qt] Periodic translation update (Fuzzbawls)

### RPC/REST
 - #877 54c8832d80 [RPC] Remove deprecated masternode/budget RPC commands (Fuzzbawls)
 - #901 be3aab4a00 [RPC] Fix typos and oversights in listunspent (CaveSpectre11)
 - #911 484c070b22 [RPC] add 'getblockindexstats' function (random-zebra)
 - #838 5673c8373e [RPC][Test] spendrawzerocoin + wrapped serials functional test (random-zebra)
 - #821 86d6133735 [RPC] Fixup signrawtransaction on regtest (Fuzzbawls)
 - #751 e820cf3816 [RPC] Show the configured/set txfee in getwalletinfo (Fuzzbawls)
 - #750 25fe72d97d [RPC] Add mediantime to getblock/getblockheader output (Fuzzbawls)
 - #760 8b79a3944a [RPC] Show BIP65 soft-fork progress in getblockchaininfo (Fuzzbawls)
 - #742 297d67b43a [RPC] Add masternode's pubkey to listmasternodes RPC (presstab)
 - #729 f84ec3df8b [RPC] Fix RPCTimerInterface (random-zebra)
 - #727 08f6e1774b [RPC] Add 'spendzerocoinmints' RPC call (random-zebra)
 - #726 8f28b7ad23 [RPC] include mints metadata in 'listmintedzerocoins' output (random-zebra)
 - #724 ee0717c2af [RPC] Ensure that a numeric is being passed to AmmountFromValue (Fuzzbawls)
 - #723 0774f5fc0d [RPC] Error when calling getreceivedbyaddress with non-wallet address (Fuzzbawls)
 - #722 3ce4fd7226 [RPC] Add more verbosity to validateaddress (Fuzzbawls)
 - #721 cecda14082 [RPC] Fix movecmd's help description to include amount (Fuzzbawls)
 - #720 056b4d5cb1 [RPC] Sanitize walletpassphrase timeout argument (Fuzzbawls)
 - #719 463fd38325 [RPC] Fix verifychain (Fuzzbawls)
 - #711 17d1f30131 [RPC] Don't allow backupwallet to overwrite the wallet-in-use (Fuzzbawls)
 - #688 64071d142d [Zerocoin] RPC import/export zerocoins private key standardized + Cleanup in AccPoK and SoK to avoid redundant calculations. (furszy)

### Wallet
 - #813 80bf51e7c9 [Refactoring] [Move Only] Move wallet files into their own folder (warrows)
 - #916 a4f02ed946 [Staking] Don't assert if we were beaten to the block (CaveSpectre11)
 - #842 c6c84fe85f [Wallet] [zPIV] Precomputed Zerocoin Proofs (Fuzzbawls)
 - #817 37a06eaa93 [Wallet] Fix segfault with runtime -disablewallet (Fuzzbawls)
 - #763 d4762f7e7a [Wallet] Add automint address (Fuzzbawls)
 - #759 19fd0877cd [Wallet] Avoid failed zPIV spend because of changed seed (warrows)
 - #755 65be6b611b [Wallet] Fix zPIV spend when too much mints are selected (warrows)
 - #734 5df105fed2 [Staking] Ensure nCredit is correctly initialized in CreateCoinStake (warrows)
 - #730 394d48b2c9 [Wallet] fix bug with fWalletUnlockAnonymizeOnly flag setting (random-zebra)
 - #715 30048cce62 [Refactor] Remove GetCoinAge (Fuzzbawls)
 - #700 a2d717090f [Wallet] Avoid autocombine getting stuck (warrows)
 - #656 5272a4f684 [Wallet] Fix double locked coin when wallet and MN are on same machine (Tim Uy)
 - #653 fdf4503b66 [Wallet] change COINBASE_MATURITY to Params().COINBASE_MATURITY() (Alko89)
 - #597 766d5196c [Wallet] Write new transactions to wtxOrdered properly (Fuzzbawls)
 - #603 779d8d597 Fix spending for v1 zPIV created before block 1050020. (presstab)
 - #617 6b525f0df [Wallet] Adjust staking properties to lower orphan rates. (presstab)
 - #625 5f2e61d60 [Wallet] Add some LOCK to avoid crash (warrows)

### Unit Tests
 - #806 fc6b5a191d [Test] Create new per-test fixtures (Wladimir J. van der Laan)
 - #902 8adeeb9727 [Tests] Add tests for CAddrMan (warrows)
 - #822 2b8daac4c0 [Tests] Integrate fake stake tests into parent test suite (Fuzzbawls)
 - #812 f8eb7feefc [Regtest][Tests][RPC] Regtest mode + Test suite. (random-zebra)

### Budget
 - #590 413fad929 [Budget] Fix wrong budget amount (Mrs-X)
 - #591 405612f3c Add unit test for budget value. (presstab)

### Miscellaneous
 - #744 7e52f58b82 [Refactor] Refactor bignum header file into several files (warrows)
 - #808 8b54f7150b [Scripts] Add optimize pngs python script (cevap)
 - #824 3323f26848 [Refactor] Remove stale obfuscation code (Fuzzbawls)
 - #830 81038da4f8 [Refactor] Remove BOOST_FOREACH (Fuzzbawls)
 - #844 0a0dcf0d4e [Refactor] Replace deprecated auto_ptr with unique_ptr (cevap)
 - #856 da26ddeeb9 [Refactor] Move per-chain budget cycle blocks to chainparams (Fuzzbawls)
 - #879 5f0d72659c [Refactor] Rename ui_interface.h file (Fuzzbawls)
 - #890 fddac44eab [Refactor] Remove unused setStakeSeen variable (warrows)
 - #903 68c81c407a [Log] Handle errors during log message formatting (warrows)
 - #904 6f597629d8 [zPIV] Free memory from ToString() (warrows)
 - #912 5f167c2c7e [Cleanup] compiler warnings in coinSpend object. (furszy)
 - #919 c0233e4af6 [zPIV] Debug missing jump line. (Matias Furszyfer)
 - #920 a56cc2948d [Docs] Overhaul documentation files (Fuzzbawls)
 - #921 893183339e [Scripts] Overhaul supplemental python/shell scripts (Fuzzbawls)
 - #926 49a69b8931 [Doc] 3.3.0 Notable Changes (Fuzzbawls)
 - #927 048d1295dc [Trivial] Update header copyright years (Fuzzbawls)
 - #865 ede1af4e10 [Main] Don't return an invalid state when shutting down the wallet (Fuzzbawls)
 - #868 a1080d8658 [Performances] Decrease the number of wasted CPU cycles (warrows)
 - #788 55ce1619f5 [Misc] Update license year 2019 (Everton Melo)
 - #736 d2ad4d6e93 [Utils] Update linters for python3 (Fuzzbawls)
 - #699 8b1f68d896 [Refactor] Use references instead of copies in for loops (Fuzzbawls)
 - #697 5a5797f5c3 [Trivial] Remove Redundant Declarations (Fuzzbawls)
 - #667 49f9a0fa9e [Zerocoin] Clean zerocoin bignum file (warrows)
 - #669 dd6909fd30 [Utils] Fix syntax error in gitian-build.sh (Aitor González)
 - #632 0d91550ff6 [MoveOnly] Move non-wallet RPC files to subdir (Fuzzbawls)
 - #731 f7f49cfa7c [zPIV] Fix bignum overloads when using OpenSSL (Fuzzbawls)
 - #692 1fde9b2b7a [Zerocoin] Remove explicit copy assignement operator from Accumulator (warrows)
 - #761 88a93bd35a [Refactoring] Abstract out and switch openssl cleanse (Adam Langley)
 - #743 af0c340fe0 [Refactor] remove CPubKey::GetHex (random-zebra)
 - #737 434abd1ae9 [Refactor] Remove 'boost::lexical_cast<>' (random-zebra)
 - #769 6482454cf6 [Main] Unify shutdown proceedure in init rather than per-app (Fuzzbawls)
 - #815 decee4bc8c [Doc] Update release notes with forthcoming 3.2.0 changes (Fuzzbawls)
 - #816 51e7b2c4b0 [Doc] Update build-unix.md (Fuzzbawls)
 - #757 a611a7fa77 [Doc] Update doc/build-windows.md (idas4you)
 - #778 65caa886ac [Doc] Update README.md (veilgets)
 - #703 51663473fc [Docs] Add missing automake dependency (Mrs-X)
 - #762 abfceb39a1 [Random] WIN32 Seed Cleanup: Move nLastPerfmon behind win32 ifdef. (21E14)
 - #771 4b1be14505 [Main] Clean up sync.cpp/h with upstream declarations (Fuzzbawls)
 - #585 76c01a560 [Doc] Change aarch assert sign output folder (Warrows)
 - #595 d2ce04cc0 [Tests] Fix chain ordering in budget tests (Fuzzbawls)
 - #611 c6a57f664 [Output] Properly log reason(s) for increasing a peer's DoS score. (Fuzzbawls)
 - #649 f6bfb4ade [Utils] Add copyright header to logprint-scanner.py (Fuzzbawls)
 - #586 fc211bfdf [Bug] Fix CMasternodeConfig::read (Fuzzbawls)
 - #587 69498104f [Bug] Fix Windows icon files (Fuzzbawls)

## Credits

Thanks to everyone who directly contributed to this release:

 - cpass78
 - minerric

 and of course
 - PIVX team for an awesome codebase