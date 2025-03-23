add_library(GameSpy STATIC

    # GameSpyHTTP
    GameSpy/common/gsCrypt.c
    GameSpy/common/gsLargeInt.c
    GameSpy/common/gsRC4.c
    GameSpy/common/gsSHA1.c
    GameSpy/common/gsSSL.c
    GameSpy/common/gsXML.c
    GameSpy/ghttp/ghttpBuffer.c
    GameSpy/ghttp/ghttpCallbacks.c
    GameSpy/ghttp/ghttpCommon.c
    GameSpy/ghttp/ghttpConnection.c
    GameSpy/ghttp/ghttpEncryption.c
    GameSpy/ghttp/ghttpMain.c
    GameSpy/ghttp/ghttpPost.c
    GameSpy/ghttp/ghttpProcess.c

    # GameSpyPresence
    GameSpy/GP/gp.c
    GameSpy/GP/gpi.c
    GameSpy/GP/gpiBuddy.c
    GameSpy/GP/gpiBuffer.c
    GameSpy/GP/gpiCallback.c
    GameSpy/GP/gpiConnect.c
    GameSpy/GP/gpiInfo.c
    GameSpy/GP/gpiKeys.c
    GameSpy/GP/gpiOperation.c
    GameSpy/GP/gpiPeer.c
    GameSpy/GP/gpiProfile.c
    GameSpy/GP/gpiSearch.c
    GameSpy/GP/gpiTransfer.c
    GameSpy/GP/gpiUnique.c
    GameSpy/GP/gpiUtility.c
    GameSpy/common/gsUdpEngine.c
    GameSpy/gt2/gt2Auth.c
    GameSpy/gt2/gt2Buffer.c
    GameSpy/gt2/gt2Callback.c
    GameSpy/gt2/gt2Connection.c
    GameSpy/gt2/gt2Filter.c
    GameSpy/gt2/gt2Main.c
    GameSpy/gt2/gt2Message.c
    GameSpy/gt2/gt2Socket.c
    GameSpy/gt2/gt2Utility.c

    # GameSpyPeer
   GameSpy/Peer/peerAutoMatch.c
   GameSpy/Peer/peerCallbacks.c
   GameSpy/Peer/peerGlobalCallbacks.c
   GameSpy/Peer/peerHost.c
   GameSpy/Peer/peerKeys.c
   GameSpy/Peer/peerMain.c
   GameSpy/Peer/peerMangle.c
   GameSpy/Peer/peerOperations.c
   GameSpy/Peer/peerPing.c
   GameSpy/Peer/peerPlayers.c
   GameSpy/Peer/peerQR.c
   GameSpy/Peer/peerRooms.c
   GameSpy/Peer/peerSB.c
   GameSpy/chat/chatCallbacks.c
   GameSpy/chat/chatChannel.c
   GameSpy/chat/chatCrypt.c
   GameSpy/chat/chatHandlers.c
   GameSpy/chat/chatMain.c
   GameSpy/chat/chatSocket.c
   GameSpy/natneg/NATify.c
   GameSpy/natneg/natneg.c
   GameSpy/pinger/pingerMain.c
   GameSpy/serverbrowsing/sb_crypt.c
   GameSpy/serverbrowsing/sb_queryengine.c
   GameSpy/serverbrowsing/sb_server.c
   GameSpy/serverbrowsing/sb_serverbrowsing.c
   GameSpy/serverbrowsing/sb_serverlist.c
   GameSpy/qr2/qr2.c
   GameSpy/qr2/qr2regkeys.c

    # GameSpyPatching
    GameSpy/common/gsAssert.c
    GameSpy/common/gsAvailable.c
    GameSpy/common/gsDebug.c
    GameSpy/common/gsMemory.c
    GameSpy/common/gsPlatform.c
    GameSpy/common/gsPlatformSocket.c
    GameSpy/common/gsPlatformThread.c
    GameSpy/common/gsPlatformUtil.c
    GameSpy/common/gsStringUtil.c
    GameSpy/ghttp/ghttpBuffer.c
    GameSpy/ghttp/ghttpCallbacks.c
    GameSpy/ghttp/ghttpCommon.c
    GameSpy/ghttp/ghttpConnection.c
    GameSpy/ghttp/ghttpMain.c
    GameSpy/ghttp/ghttpPost.c
    GameSpy/ghttp/ghttpProcess.c
    GameSpy/darray.c
    GameSpy/hashtable.c
    GameSpy/md5c.c
    GameSpy/pt/ptMain.c

    # GameSpyStats
    GameSpy/gstats/gbucket.c
    GameSpy/gstats/gstats.c
)

target_link_libraries(GameSpy INTERFACE Compiler)
