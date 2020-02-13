// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2019 The PIVX developers
// Copyright (c) 2018-2019 The BLTG developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>
#include <limits>


struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (0, uint256("0x00000ccaa671bbab8d6f72eb853466d5af0e33491fddd2861d52b394553f96f9"))
		(100, uint256("0x000002abbcebc30631f14e79d985a8c4b81d4441bbabe3e5f86b99b0e7b7660e"))
		(500, uint256("0x922d74ba02ba0d95cf0f053dcd29524a8df38c97753d89d614dce5ed526b6ea2"))
		(76901, uint256("0xa1a994c88e415a8e86a7fe2f6ba604d9743fdd77ac766d05da61eea7be2245aa"))
		(150000, uint256("0xade2e03464a19579a894ea05a38721f85f0b65357d03109bc62625e1c40c872c"))
		(300000, uint256("0xe085884a471bb5e726fe04bbef3920404b414188c008582826f6b88bc61804fd"))
        (350000, uint256("0x86860b05213436edf9201afac86fe0274459205264bfd385ef9c2f657d6ba5f1"))
        (400000, uint256("0x0214d3bed5dccf05a3f6a89ceff94519a22821d9c72a5b0a6d1079db00378876"))
        (450000, uint256("0x779c57f0219c71f5d087f0307d58d1f65ffae184421a5b25f1c9ef183583161c"))
        (500000, uint256("0xa7cd3a14decb0ae556ae1c2c1a4426bd983492ceeffc732bca234898b54f6bb1"))
        (600000, uint256("0x3f464393ad2e76350e3bf79de1380b14c074bfccc53fd5bded4bde8ec91377cb"))
        (650000, uint256("0x196c3c94eb298b1e341b2b4f5cb0ed407f303f9394ab3598ab182453f50a4fea"))
        (683265, uint256("0x0ed2fed0e0ea755ab1cfe0791dad081a3edc2f2f28c5e4dc8a2c72ce1fda1909"));


static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1581359153, // * UNIX timestamp of last checkpoint block
    1426867,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    1440        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of
    (0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    0,
    0,
    0};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    0,
    0,
    0};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const
{
    assert(this);
    static CBigNum bnHexModulus = 0;
    if (!bnHexModulus)
        bnHexModulus.SetHex(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsHex = libzerocoin::ZerocoinParams(bnHexModulus);
    static CBigNum bnDecModulus = 0;
    if (!bnDecModulus)
        bnDecModulus.SetDec(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus);

    if (useModulusV1)
        return &ZCParamsHex;

    return &ZCParamsDec;
}

bool CChainParams::HasStakeMinAgeOrDepth(const int contextHeight, const uint32_t contextTime,
        const int utxoFromBlockHeight, const uint32_t utxoFromBlockTime) const
{
    // before stake modifier V2, the age required was 60 * 60 (1 hour) / not required on regtest
    if (!IsStakeModifierV2(contextHeight))
        return (NetworkID() == CBaseChainParams::REGTEST || (utxoFromBlockTime + 3600 <= contextTime));

    // after stake modifier V2, we require the utxo to be nStakeMinDepth deep in the chain
    return (contextHeight - utxoFromBlockHeight >= nStakeMinDepth);
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x23;
        pchMessageStart[1] = 0xa3;
        pchMessageStart[2] = 0xf5;
        pchMessageStart[3] = 0xb8;
        vAlertPubKey = ParseHex("0443db95cf8f4f523fdcfa43dbb630e854e20f8816f4f399fd70a93699aa3fe2a255383df1fe36f14cf1640410d8419285b1ed4d127c2992835c72d72ee8159a73");
        nDefaultPort = 17127;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // BLTG starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 210000;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 8100; // 75%
        nRejectBlockOutdatedMajority = 10260; // 95%
        nToCheckBlockUpgradeMajority = 10800; // Approximate expected amount of blocks in 7 days (1440*7.5)
        nMinerThreads = 0;
        nTargetSpacing = 1 * 60;        // 1 minute
        nMaturity = 10;
        nStakeMinDepth = 600;
        nFutureTimeDriftPoW = 7200;
        nFutureTimeDriftPoS = 180;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 21000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 300;
        nBltgBadBlockTime = 1540080487; // Skip nBit validation of Block 301
        nBltgBadBlocknBits = 0x1e00bc6b; // Skip nBit validation of Block 301
//        nModifierUpdateBlock = 0;
        nZerocoinStartHeight = 2147483647; // Block # should start at
        nZerocoinStartTime = 2147483647; // Tue, 19 Jan 2038 03:14:07 +0000
        nBlockEnforceSerialRange = 2147483647; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 2147483647; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 2147483647; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 2147483647; //Last valid accumulator checkpoint
        //nBlockEnforceInvalidUTXO = 999999999; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0*COIN; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 2147483647; //!> The block that zerocoin v2 becomes active - roughly Tuesday, May 8, 2018 4:00:00 AM GMT
        nBlockDoubleAccumulated = 2147483647;
        nEnforceNewSporkKey = 1525158000; //!> Sporks signed after (GMT): Tuesday, May 1, 2018 7:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1527811200; //!> Fully reject old spork key after (GMT): Friday, June 1, 2018 12:00:00 AM
        nBlockStakeModifierlV2 = 694080; //!> Roughly Monday, Feb 17th, 2020 @ 1:00 PM
        // Public coin spend enforcement
        nPublicZCSpends = 2147483647;

        // Fake Serial Attack
        nFakeSerialBlockheightEnd = 0;        // We werent subjected by this, therefore shouldn't be anything to recalculate
        nSupplyBeforeFakeSerial = 0 * COIN;   // zerocoin supply at block nFakeSerialBlockheightEnd

        const char* pszTimestamp = "Boris Johnson quits to add to pressure on May over Brexit";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 50 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04c10e83b2703ccf322f7dbd62dd5855ac7c10bd055814ce121ba32607d573b8810c02c0582aed05b4deb9c4b77b26d92428c61256cd42774babea0a073b2ed0c9") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1531154631;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 1568802;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000ccaa671bbab8d6f72eb853466d5af0e33491fddd2861d52b394553f96f9"));
        assert(genesis.hashMerkleRoot == uint256("0xe456c7b894fe91492a94361376809abe1b7894ca75cbe30641b309e6d9d6b0a0"));

        vSeeds.push_back(CDNSSeedData("seed1.block-logic.com", "seed1.block-logic.com"));     // Primary DNS Seeder
        vSeeds.push_back(CDNSSeedData("seed2.block-logic.com", "seed2.block-logic.com"));    // Secondary DNS Seeder
        vSeeds.push_back(CDNSSeedData("seed3.block-logic.com", "seed3.block-logic.com"));         // Single node address

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,25);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,13);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1,145);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x03)(0x3D)(0x60)(0x66).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x03)(0x31)(0x61)(0x6B).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0xab)(0x2c).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        nBudgetCycleBlocks = 43200; //!< Amount of blocks in a months period of time (using 1 minutes per) = (60*24*30)
        strSporkKey = "04300c047237e28c6361264532ca825f409babc06f49eadca1540ea15bba9b10710dfdaf1884029d0066381dc6dded497093c7722bde5992ddb76604882514155d";
        strSporkKeyOld = "";
        strObfuscationPoolDummyAddress = "B4cgYuJAT66Jy4gXQWjJurU8k9wJ38YR2h";
        nStartMasternodePayments = 1531154631;

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMaxZerocoinPublicSpendsPerTransaction = 637; // Assume about 220 bytes each input
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nZerocoinRequiredStakeDepth = 200; //The required confirmations for a zbltg to be stakable

        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
        nProposalEstablishmentTime = 60 * 60 * 24; // Proposals must be at least a day old to make it into a budget
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }

};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x44;
        pchMessageStart[1] = 0x75;
        pchMessageStart[2] = 0x64;
        pchMessageStart[3] = 0xba;
        vAlertPubKey = ParseHex("0443db95cf8f4f523fdcfa43dbb630e854e20f8816f4f399fd70a93699aa3fe2a255383df1fe36f14cf1640410d8419285b1ed4d127c2992835c72d72ee8159a73");
        nDefaultPort = 18127;
        nEnforceBlockUpgradeMajority = 4320; // 75%
        nRejectBlockOutdatedMajority = 5472; // 95%
        nToCheckBlockUpgradeMajority = 5760; // 4 days
        nMinerThreads = 0;
        nTargetSpacing = 1 * 60;  // BLTG: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 10;
        nStakeMinDepth = 100;
        nMasternodeCountDrift = 4;
//        nModifierUpdateBlock = 0; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 43199500 * COIN;
        nZerocoinStartHeight = 2147483647;
        nZerocoinStartTime = 2147483647;
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 2147483647; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 2147483647; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 2147483647; //Last valid accumulator checkpoint
//        nBlockEnforceInvalidUTXO = 2147483647; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 2147483647; //!> The block that zerocoin v2 becomes active
        nEnforceNewSporkKey = 1521604800; //!> Sporks signed after Wednesday, March 21, 2018 4:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1522454400; //!> Reject old spork key after Saturday, March 31, 2018 12:00:00 AM GMT
        nBlockStakeModifierlV2 = 1000;
        // Public coin spend enforcement
        nPublicZCSpends = 2147483647;

        // Fake Serial Attack
        nFakeSerialBlockheightEnd = -1;
        nSupplyBeforeFakeSerial = 0;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1531154631;
        genesis.nNonce = 1568802;

        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x00000ccaa671bbab8d6f72eb853466d5af0e33491fddd2861d52b394553f96f9"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("testnet1.block-logic.com", "testnet1.block-logic.com"));
        vSeeds.push_back(CDNSSeedData("testnet2.block-logic.com", "testnet2.block-logic.com"));
        vSeeds.push_back(CDNSSeedData("testnet3.block-logic.com", "testnet3.block-logic.com"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet bltg addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet bltg script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet bltg BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet bltg BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet bltg BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        nBudgetCycleBlocks = 144; //!< Ten cycles per day on testnet
        strSporkKey = "04238a360e5b459484eb1990f1fbdcc162c577979f325b6c74569251bcdb2efe866351f32ae0755c864a3e85e50da3e242202e75dd11e8e98543a51957c4efa6d4";
        //strSporkKeyOld = "";
        strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet

        nProposalEstablishmentTime = 60 * 5; // Proposals must be at least 5 mns old to make it into a test budget
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xc1;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0x7d;
        pchMessageStart[3] = 0x3c;
        nDefaultPort = 19127;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetSpacing = 1 * 60;        // BLTG: 1 minute
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        nLastPOWBlock = 250;
        nMaturity = 10;
        nStakeMinDepth = 0;
        nMasternodeCountDrift = 4;
//        nModifierUpdateBlock = 0; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 43199500 * COIN;
        nZerocoinStartHeight = 300;
        nBlockZerocoinV2 = 300;
        nZerocoinStartTime = 2147483647;
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 2147483647; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 2147483647; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 2147483647; //Last valid accumulator checkpoint
        nBlockStakeModifierlV2 = std::numeric_limits<int>::max(); // max integer value (never switch on regtest)
        // Public coin spend enforcement
        nPublicZCSpends = 350;

        // Fake Serial Attack
        nFakeSerialBlockheightEnd = -1;

        //! Modify the regtest genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1531154631;
        genesis.nNonce = 1568802;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000ccaa671bbab8d6f72eb853466d5af0e33491fddd2861d52b394553f96f9"));


        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fSkipProofOfWorkCheck = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 19129;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;

static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
