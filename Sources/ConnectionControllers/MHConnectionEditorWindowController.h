//
//  MHConnectionEditorWindowController.h
//  MongoHub
//
//  Created by Jérôme Lebel on 19/08/2012.
//

#import <Cocoa/Cocoa.h>
@class MHConnectionStore;
@class MHConnectionEditorWindowController;
@class ConnectionsArrayController;

@protocol MHConnectionEditorWindowControllerDelegate <NSObject>
@property (nonatomic, strong, readonly) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, strong, readonly) ConnectionsArrayController *connectionsArrayController;

- (void)connectionWindowControllerDidCancel:(MHConnectionEditorWindowController *)controller;
- (void)connectionWindowControllerDidValidate:(MHConnectionEditorWindowController *)controller;
- (MHConnectionStore *)connectionWindowController:(MHConnectionEditorWindowController *)controller connectionStoreWithAlias:(NSString *)alias;

@end

@interface MHConnectionEditorWindowController : NSWindowController
{
    NSTextField                         *_aliasTextField;

    NSPopUpButton                       *_singleReplicaSetPopUpButton;
    NSTabView                           *_singleReplicaSetTabView;

    // single server
    NSTextField                         *_hostTextField;
    NSTextField                         *_hostportTextField;
    NSButton                            *_slaveOkButton;
    
    // replica set
    NSTextField                         *_replicaSetNameTextField;
    NSTextField                         *_replicaSetServersTextField;
    NSPopUpButton                       *_defaultReadModePopUpButton;
    
    // sharded cluster
    NSTextField                         *_shardedClusterServersTextField;
    
    NSTextField                         *_adminUserTextField;
    NSSecureTextField                   *_adminPasswordTextField;
    NSTextField                         *_defaultDatabaseTextField;
    
    NSButton                            *_useSSLCheckbox;
    NSButton                            *_weakCertificateCheckbox;
    
    NSButton                            *_useSSHCheckBox;
    NSTextField                         *_sshHostTextField;
    NSTextField                         *_sshPortTextField;
    NSTextField                         *_sshUserTextField;
    NSSecureTextField                   *_sshPasswordTextField;
    NSTextField                         *_sshKeyfileTextField;
    
    NSButton                            *_selectKeyFileButton;
    NSButton                            *_addSaveButton;
    
    id<MHConnectionEditorWindowControllerDelegate> _delegate;
}
@property (nonatomic, readwrite, strong) MHConnectionStore *editedConnectionStore;
@property (nonatomic, readwrite, strong) MHConnectionStore *connectionStoreDefaultValue;
@property (nonatomic, readwrite, weak) id<MHConnectionEditorWindowControllerDelegate> delegate;
@property (nonatomic, readonly, assign, getter=isNewConnetion) BOOL newConnection;

- (void)modalForWindow:(NSWindow *)window;
- (NSManagedObjectContext *)managedObjectContext;

@end
