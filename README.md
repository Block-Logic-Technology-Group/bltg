BLTG Core integration/staging repository
=====================================

[![master Actions Status](https://github.com/Block-Logic-Technology-Group/bltg/workflows/CI%20Actions%20for%20BLTG/badge.svg)](https://github.com/Block-Logic-Technology-Group/bltg/actions)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/Block-Logic-Technology-Group/bltg/bltg?color=%235c4b7d&cacheSeconds=3600)](https://github.com/Block-Logic-Technology-Group/bltg/releases)
[![GitHub Release Date](https://img.shields.io/github/release-date/Block-Logic-Technology-Group/bltg/bltg?color=%235c4b7d&cacheSeconds=3600)](https://github.com/Block-Logic-Technology-Group/bltg/releases)

## What is BLTG?

BLTG is an open source community-driven cryptocurrency, focused on five main aspects:

(1) User Data Protection: Through the use of SHIELD, a zk-SNARKs based privacy protocol.

(2) Low environmental footprint and network participation equality: Through the use of a highly developed Proof of Stake protocol.

(3) Decentralized Governance System: A DAO built on top of the tier two Masternodes network, enabling a monthly community treasury, proposals submission and decentralized voting.

(4) Fast Transactions: Through the use of fast block times and the tier two network, BLTG is committed to continue researching new and better instant transactions mechanisms.

(5) Ease of Use: BLTG is determined to offer the best possible graphical interface for a core node/wallet. A full featured graphical product for new and advanced users.

A lot more information and specs at [https://block-logic.com/](https://block-logic.com/). Join the community at [BLTG Discord](https://discord.block-logic.com/).

*33 000 300 BLTG Premine

### Reward Distribution

<table>
<th colspan=4>Genesis Block</th>
<tr><th>Block Height</th><th>Reward Amount</th><th>Notes</th></tr>
<tr><td>1 - 11</td><td>3000,000 BLTG</td><td>Initial Pre-mine. </td></tr>
</table>

### PoW and PoS Rewards Breakdown

<table>
<th>Block Height</th><th>Stakers</th><th>Masternodes</th><th>Budget *</th>
<tr><td>11-300</td><td>40% (0.40 BLTG)</td><td>60% (0.60 BLTG)</td><td>N/A</td></tr>
<tr><td>301-20200</td><td>20% (0.20 BLTG)</td><td>80% (0.80 BLTG)</td><td>20% (0.20 BLTG)</td></tr>
<tr><td>20201-279400</td><td>20% (2 BLTG)</td><td>80% (8 BLTG)</td><td>20% (2 BLTG)</td></tr>
<tr><td>279401-538600</td><td>20% (1.8 BLTG)</td><td>80% (7.2 BLTG)</td><td>20% (1.8 BLTG)</td></tr>
<tr><td>538601-797800</td><td>20% (1.6 BLTG)</td><td>80% (6.4 BLTG)</td><td>20% (1.6 BLTG)</td></tr>
<tr><td>797801-1057000</td><td>20% (1.4 BLTG)</td><td>80% (5.6 BLTG)</td><td>20% (1.4 BLTG)</td></tr>
<tr><td>1057001-1316200</td><td>20% (1.2 BLTG)</td><td>80% (4.8 BLTG)</td><td>20% (1.2 BLTG)</td></tr>
<tr><td>1316201-1575400</td><td>20% (1 BLTG)</td><td>80% (4 BLTG)</td><td>20% (1 BLTG)</td></tr>
<tr><td>1575401-Infinite</td><td>20% (1 BLTG)</td><td>80% (4 BLTG)</td><td>20% (1 BLTG)</td></tr>
</table>

## Development Process

The master branch is regularly built (see doc/build-*.md for instructions) and tested, but it is not guaranteed to be completely stable. [Tags](https://github.com/Block-Logic-Technology-Group/bltg/tags) are created regularly from release branches to indicate new official, stable release versions of BLTG Core.

The contribution workflow is described in [CONTRIBUTING.md](https://github.com/Block-Logic-Technology-Group/bltg/blob/master/CONTRIBUTING.md) and useful hints for developers can be found in [doc/developer-notes.md](https://github.com/Block-Logic-Technology-Group/bltg/blob/master/doc/developer-notes.md).

## Testing

Testing and code review is the bottleneck for development; we get more pull requests than we can review and test on short notice. Please be patient and help out by testing other people's pull requests, and remember this is a security-critical project where any mistake might cost people a lot of money.

## Automated Testing

Developers are strongly encouraged to write [unit tests](https://github.com/Block-Logic-Technology-Group/bltg/blob/master/src/test/README.md) for new code, and to submit new unit tests for old code. Unit tests can be compiled and run (assuming they weren't disabled in configure) with: make check. Further details on running and extending unit tests can be found in [/src/test/README.md](https://github.com/Block-Logic-Technology-Group/bltg/blob/master/src/test/README.md).

There are also regression and integration tests, written in Python. These tests can be run (if the test dependencies are installed) with: test/functional/test_runner.py`

The CI (Continuous Integration) systems make sure that every pull request is built for Windows, Linux, and macOS, and that unit/sanity tests are run automatically.

## Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the code. This is especially important for large or high-risk changes. It is useful to add a test plan to the pull request description if testing the changes is not straightforward.

## License
BLTG Core is released under the terms of the MIT license. See [COPYING](https://github.com/Block-Logic-Technology-Group/bltg/blob/master/COPYING) for more information or see https://opensource.org/licenses/MIT.


